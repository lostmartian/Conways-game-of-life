# Conway's Game of Life

## C++ simulation of the greatest cellular automaton

![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.

The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## Installation

You need a C++ compiler (GCC prefered) to run the simulation. Also change the gcc flag in the make file accourding to your system preference.
Run the following commands.

```sh
git clone https://github.com/lostmartian/Game-of-Life-CPP-Simulator.git
cd src
make
./game
```

Some simulations are shown in the readme_files folder do check that out. Also sample test configurations are loaded in the test folder.

Sample glider

![Glider](https://user-images.githubusercontent.com/62000079/121061552-9cf80100-c7e1-11eb-953f-4a1516675455.mov)
