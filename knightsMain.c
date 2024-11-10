// Alex Ryse CS361 Lab3
// knightsMain.c

/*
    terminal command line to compile program:  gcc -o main *.c -Wall
    terminal command line to start program: ./main "enter size of the board"
*/

#include <stdio.h>
#include <stdlib.h>
#include "knights.h"

int main(int argc, char *argv[])
{
    // check if more than one command line argument (argv[0] = executable file, argv[1] = board size)
    if (argc > 2 || argc <= 1)
    {
        printf("Enter only one value for board size\n");
        return 0; // exit program
    }

    // intialize the size of the board (command line argument) and (x, y) coordinates
    int size = atoi(argv[1]), x = 0, y = 0;

    // get x and y coordinates (user input) and display to the user
    printf("Enter x coordinate: ");
    scanf("%d", &x);
    printf("Enter y coordinate: ");
    scanf("%d", &y);

    // check if x and(or) y coordinates are valid (cannot be negative or greater than the size of the board)
    if ((x < 0 || x >= size) || (y < 0 || y >= size))
    {
        printf("Enter a valid x and(or) y coordinate(s)\n");
        return 0; // exit program
    }

    // check if the board size is one (automatic success depending on if the (x, y) coordinates are valid)
    if (size == 1)
    {
        printf("1\nsuccess\n");
        return 0; // exit program
    }

    // initialize the board
    int board[size][size];

    // set the moveCount to 1, signifying the knight's starting positions
    // int moveCount = 1;

    // set the board with all 0's
    initBoard(size, board);

    // print the board to the terminal
    printBoard(size, board);

    // all possible moves for the knight
    const int XMOVES[NUMMOVES] = {1, 1, -1, -1, 2, 2, -2, -2};
    const int YMOVES[NUMMOVES] = {2, -2, 2, -2, 1, -1, 1, -1};

    // set the knight's starting point to 1
    board[x][y] = 1;

    // execute back tracking, if backTrack is unsuccessfull, returns 0 (false)
    if (!backTrack(size, board, x, y, XMOVES, YMOVES))
    {
        printf("No solution\n");
        return 0; // exit program
    }
    else
    {
        printf("Success\n");
        return 0; // successfully exit the program
    }
}