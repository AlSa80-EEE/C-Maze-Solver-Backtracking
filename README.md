# Maze Solver with Backtracking (C)

A robust maze-solving application developed in C using the **Backtracking** algorithm. This project demonstrates efficient recursion, dynamic memory management, and algorithmic complexity analysis.

## 💡 Key Features
- **Dynamic Grid Sizing:** Uses `malloc` and `free` for handling any maze dimension.
- **Recursive Backtracking:** Explores all possible paths (Up, Down, Left, Right) to find the exit.
- **Memory Efficient:** Ensures no memory leaks by proper deallocation of 2D pointers.

## 🛠️ Tech Stack
- **Language:** C (Standard: C11)
- **Concepts:** Recursion, Pointers, Memory Management.

## 🚀 How to Run
1. Clone the repo: `git clone https://github.com/username/C-Maze-Solver-Backtracking.git`
2. Compile: `gcc src/maze_solver.c -o maze_solver`
3. Run: `./maze_solver`

## 📊 Logic Overview
The algorithm marks its path with `*`. If it hits a dead end (wall or blocked path), it **backtracks** to the previous junction and tries a different direction.
