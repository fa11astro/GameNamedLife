# Game of Life 🎮

## Project Overview

**Game of Life** is a cellular automaton created by British mathematician John Conway in 1970. This project implements the Game of Life using an Arduino microcontroller and an LED display. The game simulates the evolution of a grid of cells based on simple rules, creating fascinating patterns and behaviors.

---

## 📝 Note

**This is a school project created for educational purposes.** The implementation is designed as a learning exercise to understand cellular automata and microcontroller programming. Please don't take this project too seriously - it's meant to be fun and educational app)

---

## Features 🌟

- **Cellular Automaton**: Simulates the Game of Life on a grid.
- **Random Initialization**: The initial state of the grid is randomly generated.
- **Display Output**: Visualizes the game state on an LED display.
- **Dynamic Evolution**: The grid evolves over generations based on predefined rules.

---

## How It Works 🛠️

The game operates on a rectangular grid where each cell can be either "alive" (1) or "dead" (0). The grid is surrounded by empty cells that do not change during the game. Each cell has eight neighbors, and the state of the grid evolves based on the following rules:

1. A live cell with fewer than two live neighbors dies (underpopulation).
2. A live cell with two or three live neighbors lives on to the next generation.
3. A live cell with more than three live neighbors dies (overpopulation).
4. A dead cell with exactly three live neighbors becomes alive (reproduction).

The game ends when all cells die or when the grid reaches a stable configuration.

---

## Project Structure 📁

```
GameOfLife/
├── .git/                 # Git version control files
├── README.md             # Project documentation
├── gameNamedLife.cpp     # C++ implementation for PC
└── gameNamedLife.ino     # Arduino implementation
```

---

## Installation 🚀

To set up the project locally:

1. Clone the repository:
   ```bash
   git clone https://github.com/fa11astro/GameNamedLife.git
   cd GameNamedLife
   ```

2. Open the `gameNamedLife.ino` file in the Arduino IDE.

3. Connect your Arduino board and upload the sketch.

4. Run the program to see the Game of Life in action on your LED display!

---

## Usage 📡

Once the program is running, the LED display will show the initial state of the grid. The grid will evolve over time, displaying the changes in cell states according to the rules of the Game of Life. You can observe how patterns emerge and change dynamically.

---

## Contributing 🤝

Contributions are welcome! If you would like to contribute to the Game of Life project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Push your changes to your forked repository.
5. Create a pull request.

---

Thank you for checking out the Game of Life project! If you have any questions or feedback, feel free to reach out! 😊
