#pragma once
#include <iostream>
const int ROW = 3;
const int COLUMN = 3;

class board
{
public:
	int state[ROW][COLUMN] = 
	{
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	bool complete = false;
	bool playerWin = false;
	int moves = 0;
};

void drawBoard(board gameBoard);
void userMove(board &gameBoard);
bool validMove(board gameBoard, std::string userMove);
bool checkHumanWin(board gameBoard);
bool checkAIWin(board gameBoard);



