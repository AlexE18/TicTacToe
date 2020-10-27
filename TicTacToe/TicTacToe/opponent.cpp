#include "opponent.h"
#include "board.h"
#include <stdlib.h>
#include <time.h>
int opponentMove(board &gameBoard, int depth, bool aiTurn) {
	int totalScore;
	int moveI = -1;
	int moveJ = -1;
	if (checkAIWin(gameBoard)) {
		return 1; 
	}
	else if (checkHumanWin(gameBoard)) {
		return -1; 
	}
	else if (gameBoard.moves >= 9) {
		return 0;
	}
	srand(time(NULL));
	if (aiTurn) {
		totalScore = -10000; 
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COLUMN; j++) {
				if (gameBoard.state[i][j] == 0) {
					board newBoard = gameBoard;
					newBoard.moves++;
					newBoard.state[i][j] = -1;
					int score = opponentMove(newBoard, depth + 1, false);
					if (score > totalScore) { 
						totalScore = score;
						moveI = i;
						moveJ = j;
					}
					else if (score == totalScore && (rand() % 10 + 1 > 5)) {
						totalScore = score;
						moveI = i;
						moveJ = j;
					}
				}
			}
		}
	}
	else {
		totalScore = 10000; 
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COLUMN; j++) {
				if (gameBoard.state[i][j] == 0) {
					board newBoard = gameBoard;
					newBoard.moves++;
					newBoard.state[i][j] = 1;
					int score = opponentMove(newBoard, depth + 1, true);
					if (score < totalScore) {
						totalScore = score;
						moveI = i;
						moveJ = j;
					}
					else if (score == totalScore && (rand() % 10 + 1 > 5)) {
						totalScore = score;
						moveI = i;
						moveJ = j;
					}
				}
			}
		}
	}

	if (depth == 0) {
		gameBoard.state[moveI][moveJ] = -1; //Make the most efficient move
		return 0;
	}
	else {
		return totalScore;
	}

}
