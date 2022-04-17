#define WORLD_HEIGHT 5
#define WORLD_WIDTH 5

using namespace std;

struct point {
    bool isLive : 1;
};

void setup() {
    //setlocale(LC_ALL, "Russian");

    point world[WORLD_WIDTH][WORLD_HEIGHT];
    point previousWorld[WORLD_WIDTH][WORLD_HEIGHT];

    setFirstLife(world);
    int liveCells = -1;
    bool isOptimalConfig = 0;

    do {
        printWorld(world);
        copyingWorld(world, previousWorld);
        nextGeneration(world, previousWorld);

        isOptimalConfig = comparingWorlds(world, previousWorld) == 0;
        liveCells = countLiveCells(world);

        if (isOptimalConfig)
        {
            Serial.println("Сложилась стабильная конфигурация");
            Serial.println();
        }
        else if (liveCells == 0)
        {
            Serial.println("Все клетки умерли");
            Serial.println();
        }

        delay(1000);
    } while (liveCells != 0 && !isOptimalConfig);
}

void loop() {
    
}

// генерация первой жизни в мире
void setFirstLife(point world[][WORLD_HEIGHT])
{
    for (int i = 0; i < WORLD_WIDTH; i++)
    {
        for (int j = 0; j < WORLD_HEIGHT; j++)
        {
            int num = random(1, 25);
            if (num % 2 == 0)

            {
                world[i][j].isLive = 1;
            }
            else
            {
                world[i][j].isLive = 0;
            }
        }
    }
}

// вывод на дисплей
void printWorld(point world[][WORLD_HEIGHT])
{
    for (int i = 0; i < WORLD_WIDTH; i++)
    {
        for (int j = 0; j < WORLD_HEIGHT; j++)
        {
            if (world[i][j].isLive == 1)
            {
                Serial.print('*');
            }
            else
            {
                Serial.print(' ');
            }

            Serial.print(' ');
        }
        Serial.println();
    }
    Serial.println("поколение");
    Serial.println();
}

// количество живых клеток в мире
int countLiveCells(point world[][WORLD_HEIGHT])
{
    int count = 0;

    for (int i = 0; i < WORLD_WIDTH; i++)
    {
        for (int j = 0; j < WORLD_HEIGHT; j++)
        {
            if (world[i][j].isLive == 1)
            {
                count++;
            }
        }
    }

    return count;
}

// получение координат соседей клетки
void neighborsCoordinates(int neighbor[][2], int x, int y)
{
    int k = 0;

    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i != x && j != y)
            {
                neighbor[k][0] = i;
                neighbor[k][1] = j;
                k++;
            }
        }
    }
}

// количество живых соседей у клетки
int countLiveNeighbors(point world[][WORLD_HEIGHT], int x, int y)
{
    int count = 0;
    int neighbor[8][2];
    int new_x, new_y;

    neighborsCoordinates(neighbor, x, y);

    for (int i = 0; i < 8; i++)
    {
        new_x = neighbor[i][0];
        new_y = neighbor[i][1];

        if ((new_x >= 0 && new_y >= 0) && (new_x < WORLD_WIDTH && new_y < WORLD_HEIGHT) && (world[new_x][new_y].isLive == 1))
        {
            count++;
        }
    }

    return count;
}

// генерация следующего поколения
void nextGeneration(point world[][WORLD_HEIGHT], point previousWorld[][WORLD_HEIGHT])
{
    int liveNeighbor;

    for (int i = 0; i < WORLD_WIDTH; i++)
    {
        for (int j = 0; j < WORLD_HEIGHT; j++)
        {
            liveNeighbor = countLiveNeighbors(previousWorld, i, j);

            if ((previousWorld[i][j].isLive == 0) && (liveNeighbor == 3))
            {
                world[i][j].isLive = 1;
            }
            else if (liveNeighbor < 2 || liveNeighbor > 3)
            {
                world[i][j].isLive = 0;
            }
        }
    }
}

// копирование нынешнего поколения для сравнения со следующим
void copyingWorld(point thisWorld[][WORLD_HEIGHT], point copyWorld[][WORLD_HEIGHT])
{
    for (int i = 0; i < WORLD_WIDTH; i++)
    {
        for (int j = 0; j < WORLD_HEIGHT; j++)
        {
            copyWorld[i][j] = thisWorld[i][j];
        }
    }
}

// сравнение текущего и предыдущего поколения
int comparingWorlds(point world[][WORLD_HEIGHT], point previousWorld[][WORLD_HEIGHT])
{
    for (int i = 0; i < WORLD_WIDTH; i++)
    {
        for (int j = 0; j < WORLD_HEIGHT; j++)
        {
            if (world[i][j].isLive != previousWorld[i][j].isLive)
            {
                return -1;
            }
        }
    }
    return 0;
}
