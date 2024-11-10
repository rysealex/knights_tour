// Alex Ryse CS361 Lab3
// knights.h

#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <stdio.h>
#include <unistd.h>

#define NUMMOVES 8 // number of total possible moves for the knight

// function declarations

// initBoard function
void initBoard(int size, int board[size][size]);

// printBoard function
void printBoard(int size, int board[size][size]);

// isOk function
char isOk(int size, int board[size][size], int posX, int posY);

// markOk function (Optimized Solution)
void markOk(int size, int board[size][size], int posX, int posY);

/*
    markOk and backTrack function declarations for the Original Solution

    void markOk(int size, int board[size][size], int moveCount, int posX, int posY);
    char backTrack(int size, int board[size][size], int moveCount, int posX, int posY, const int XMOVES[NUMMOVES], const int YMOVES[NUMMOVES]);
*/

// getBoardSize function
int getBoardSize(int size);

// backTrack function (Optimized Solution)
char backTrack(int size, int board[size][size], int posX, int posY, const int XMOVES[NUMMOVES], const int YMOVES[NUMMOVES]);

#endif