// Alex Ryse CS361 Lab3
// knights.c

#include "knights.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// global variable moveCount (Optimized Solution)
int moveCount = 1;

// function definitions

// initBoard function
void initBoard(int size, int board[size][size])
{
    for (int i = 0; i < size; i++)
    {
        memset(board[i], 0, sizeof(int) * size); // initialize with 0's
    }
}

// printBoard function
void printBoard(int size, int board[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]); // display in terminal
        }
        printf("\n");
    }
}

// isOk function
char isOk(int size, int board[size][size], int posX, int posY)
{
    // check if possible move (not outside the left, right, top, and bottom boundaries of the board)
    // (and not greater than the board size)
    if ((posX) >= 0 && (posX) < size && (posY) >= 0 && (posY) < size)
    {
        if (board[posX][posY] == 0) // check if available spot on the board
        {
            return 1; // return true
        }
        else
        {
            return 0; // if not available spot, return false
        }
    }
    else
        return 0; // if not possible move, return false
}

// markOk function
void markOk(int size, int board[size][size], int posX, int posY)
{
    board[posX][posY] = moveCount; // update available spot on the board
}

// getBoardSize function
int getBoardSize(int size)
{
    return size * size; // return size of the board
}

/*
    Optimizied Solution: Faster but does not find accurate solution
*/

// backTrack function
char backTrack(int size, int board[size][size], int posX, int posY, const int XMOVES[NUMMOVES], const int YMOVES[NUMMOVES])
{
    // initialize tempX and tempY
    int tempX = 0, tempY = 0;

    // check if knight has successfully traversed the board
    if (moveCount == (size * size))
    {
        return 1; // return true
    }
    // iterate through each possible moves from the current position (posX, posY)
    for (int i = 0; i < NUMMOVES; i++)
    {
        // tempX and tempY set to the new possible position
        tempX = posX + XMOVES[i];
        tempY = posY + YMOVES[i];
        // check if the new possible position is valid
        if (isOk(size, board, tempX, tempY))
        {
            // increment moveCount
            moveCount++;
            // update the board with the new possible position, increment moveCount to signify this position
            markOk(size, board, tempX, tempY);
            // clear the terminal
            system("clear");
            // print the updated board to the user
            printBoard(size, board);
            // pause the program for one second after each update for user readability
            sleep(1);
            // recursively call backTrack with the new possible position, and check if returns true
            if (backTrack(size, board, tempX, tempY, XMOVES, YMOVES))
                return 1;
            // backtracking here
            /*else
                board[tempX][tempY] = 0; // reset the new possible position to 0*/
        }
    }
    return 0; // if no possible moves from the current position are successfull, return false
}

/*
    Original Solution: Slower but finds the accurate solution
*/

/*// backTrack function
char backTrack(int size, int board[size][size], int moveCount, int posX, int posY, const int XMOVES[NUMMOVES], const int YMOVES[NUMMOVES])
{
    // initialize tempX and tempY
    int tempX = 0, tempY = 0;

    // check if knight has successfully traversed the board
    if (moveCount == (size * size))
    {
        return 1; // return true
    }
    // iterate through each possible moves from the current position (posX, posY)
    for (int i = 0; i < NUMMOVES; i++)
    {
        // tempX and tempY set to the new possible position
        tempX = posX + XMOVES[i];
        tempY = posY + YMOVES[i];
        // check if the new possible position is valid
        if (isOk(size, board, tempX, tempY))
        {
            // update the board with the new possible position, increment moveCount to signify this position
            markOk(size, board, moveCount + 1, tempX, tempY);
            // clear the terminal
            system("clear");
            // print the updated board to the user
            printBoard(size, board);
            // pause the program for one second after each update for user readability
            sleep(1);
            // recursively call backTrack with the new possible position, and check if returns true
            if (backTrack(size, board, moveCount + 1, tempX, tempY, XMOVES, YMOVES))
                return 1;
            // backtracking here
            else
                board[tempX][tempY] = 0; // reset the new possible position to 0
        }
    }
    return 0; // if no possible moves from the current position are successfull, return false
}*/