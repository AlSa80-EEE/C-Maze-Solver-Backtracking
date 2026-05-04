CC = gcc
CFLAGS = -Wall -g

all: maze_solver

maze_solver: src/maze_solver.c
	$(CC) $(CFLAGS) src/maze_solver.c -o maze_solver

clean:
	rm -f maze_solver
