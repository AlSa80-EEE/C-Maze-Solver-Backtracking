#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int **maze;
char **solution;
int rows, cols;

void printInputMaze() {
    printf("\n--- Input Maze Configuration ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}


void printSolution() {
    printf("\n--- Calculated Solution Path ---\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", solution[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int r, int c) {
    return (r >= 0 && r < rows && c >= 0 && c < cols && 
            maze[r][c] == 0 && solution[r][c] == '0');
}


bool solveMaze(int r, int c) {
    
    if (r == rows - 1 && c == cols - 1) {
        solution[r][c] = '*';
        return true;
    }

    if (isSafe(r, c)) {
      
        solution[r][c] = '*';

        
        if (solveMaze(r, c + 1)) return true;
        if (solveMaze(r + 1, c)) return true;
        if (solveMaze(r, c - 1)) return true;
        if (solveMaze(r - 1, c)) return true;

       
        solution[r][c] = '0'; 
        return false;
    }
    return false;
}

int main() {
    printf("Enter dimensions (rows columns): ");
    if (scanf("%d %d", &rows, &cols) != 2) return 1;

   
    maze = (int **)malloc(rows * sizeof(int *));
    solution = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        maze[i] = (int *)malloc(cols * sizeof(int));
        solution[i] = (char *)malloc(cols * sizeof(char));
    }

    printf("Enter the maze layout (0 for path, 1 for wall):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
            solution[i][j] = (maze[i][j] == 1) ? '1' : '0';
        }
    }

    printInputMaze();

    
    if (maze[0][0] == 1 || maze[rows-1][cols-1] == 1 || !solveMaze(0, 0)) {
        printf("\nRESULT: No valid path exists from start to finish.\n");
    } else {
        printSolution();
    }

  
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
        free(solution[i]);
    }
    free(maze);
    free(solution);

    return 0;
}
