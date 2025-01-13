# Game of Life

This project implements Conway's Game of Life using the SFML library in C++. The program visualizes a grid-based cellular automaton where each cell follows simple rules to "live" or "die," simulating life-like behavior.

## Features

- **Interactive Grid**: Click on cells to activate or deactivate them.
- **Simulation Controls**: Use the spacebar to start or pause the simulation.
- **Dynamic Updates**: Observe the grid evolve based on the rules of Conway's Game of Life.

## How to Build and Run

### Prerequisites

1. **SFML Library**: Install the SFML library from [SFML's website](https://www.sfml-dev.org/).
2. **C++ Compiler**: Ensure you have a modern C++ compiler (e.g., GCC, Clang, or MSVC).

### Building

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-folder>
   ```
2. Compile the code:
   ```bash
   g++ -o game_of_life main.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```

3. Run the program:
   ```bash
   ./game_of_life
   ```

## Usage

1. **Start the Program**: Launch the compiled binary to open the simulation window.
2. **Interact with the Grid**:
   - Click on cells to activate them (white) or deactivate them.
3. **Control the Simulation**:
   - Press the spacebar to toggle the simulation state (start/pause).
4. **Observe**: Watch how the cells evolve over time based on Conway's rules:
   - A live cell survives with 2 or 3 live neighbors.
   - A dead cell becomes live if it has exactly 3 live neighbors.
   - All other cells die or remain dead.

## Contribution

Feel free to fork the repository and submit pull requests. Suggestions for improving performance or adding features are welcome.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgments

- Conway's Game of Life: [Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
- SFML: [Simple and Fast Multimedia Library](https://www.sfml-dev.org/)

