#include "board.h"
#include "opponent.h"
#include <iostream>

void drawBoard(board gameBoard) {
	std::cout << "    A   B   C\n";
	std::cout << "  -------------\n1";
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (!gameBoard.state[i][j]) {
				std::cout << " | -";
			}
			else if (gameBoard.state[i][j] == 1) {
				std::cout << " | O";
			}
			else {
				std::cout << " | X";
			}
		}
		if (i < ROW - 1) {
			std::cout << " | \n  -------------\n" << i + 2;
		}
		else {
			std::cout << " | \n  -------------\n";
		}
	}
}

void userMove(board& gameBoard) {
	std::string userMove;
	while (true) {
		std::cout << "Enter Move: ";
		std::cin >> userMove;
		if (validMove(gameBoard, userMove)) {
			break;
		}
		std::cout << "Invalid Move\n";
	}
	if (userMove == "A1") {
		gameBoard.state[0][0] = 1;
	}
	else if (userMove == "A2") {
		gameBoard.state[1][0] = 1;
	}
	else if (userMove == "A3") {
		gameBoard.state[2][0] = 1;
	}
	else if (userMove == "B1") {
		gameBoard.state[0][1] = 1;
	}
	else if (userMove == "B2") {
		gameBoard.state[1][1] = 1;
	}
	else if (userMove == "B3") {
		gameBoard.state[2][1] = 1;
	}
	else if (userMove == "C1") {
		gameBoard.state[0][2] = 1;
	}
	else if (userMove == "C2") {
		gameBoard.state[1][2] = 1;
	}
	else if (userMove == "C3") {
		gameBoard.state[2][2] = 1;
	}
}

bool validMove(board gameBoard, std::string userMove) {
	if (userMove == "A1" && gameBoard.state[0][0] == 0) {
		return true;
	}
	else if (userMove == "A2" && gameBoard.state[1][0] == 0) {
		return true;
	}
	else if (userMove == "A3" && gameBoard.state[2][0] == 0) {
		return true;
	}
	else if (userMove == "B1" && gameBoard.state[0][1] == 0) {
		return true;
	}
	else if (userMove == "B2" && gameBoard.state[1][1] == 0) {
		return true;
	}
	else if (userMove == "B3" && gameBoard.state[2][1] == 0) {
		return true;
	}
	else if (userMove == "C1" && gameBoard.state[0][2] == 0) {
		return true;
	}
	else if (userMove == "C2" && gameBoard.state[1][2] == 0) {
		return true;
	}
	else if (userMove == "C3" && gameBoard.state[2][2] == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool checkAIWin(board gameBoard) {
	for (int i = 0; i < ROW; i++) {
		if (gameBoard.state[i][0] + gameBoard.state[i][1] + gameBoard.state[i][2] == -3) {
			return true;
		}
	}
	for (int i = 0; i < COLUMN; i++) {
		if (gameBoard.state[0][i] + gameBoard.state[1][i] + gameBoard.state[2][i] == -3) {
			return true;
		}
	}
	if (gameBoard.state[0][0] + gameBoard.state[1][1] + gameBoard.state[2][2] == -3) {
		return true;
	}
	else if (gameBoard.state[2][0] + gameBoard.state[1][1] + gameBoard.state[0][2] == -3) {
		return true;
	}
	return false;
}

bool checkHumanWin(board gameBoard) {
	for (int i = 0; i < ROW; i++) {
		if (gameBoard.state[i][0] + gameBoard.state[i][1] + gameBoard.state[i][2] == 3) {
			return true;
		}
		
	}
	for (int i = 0; i < COLUMN; i++) {
		if (gameBoard.state[0][i] + gameBoard.state[1][i] + gameBoard.state[2][i] == 3) {
			return true;
		}
		
	}
	if (gameBoard.state[0][0] + gameBoard.state[1][1] + gameBoard.state[2][2] == 3) {
		return true;
	}
	else if (gameBoard.state[2][0] + gameBoard.state[1][1] + gameBoard.state[0][2] == 3) {
		return true;
	}
	return false;
}


// Main Function
int main() {
	board gameBoard;
	int firstOrSecond;
	while (true) {
		std::cout << "1: Play First\n2: Play Second\n";
		std::cin >> firstOrSecond;
		if (firstOrSecond == 1 || firstOrSecond == 2) {
			break;
		}
		std::cout << "Type 1 or 2\n";
	}

	while (!gameBoard.complete) {
		if (firstOrSecond == 2) {
			opponentMove(gameBoard, 0, true);
			gameBoard.moves++;
			firstOrSecond = 0;
		}
		drawBoard(gameBoard);
		userMove(gameBoard); //Passes by reference (be careful)
		gameBoard.moves++;
		if (gameBoard.moves >= 9) {
			gameBoard.complete = true;
			break;
		}
		if (checkHumanWin(gameBoard)) {
			gameBoard.playerWin = true;
			gameBoard.complete = true;
			break;
		}
		opponentMove(gameBoard, 0, true);
		gameBoard.moves++;
		if (gameBoard.moves >= 9) {
			gameBoard.complete = true;
			break;
		}
		if (checkAIWin(gameBoard)) {
			gameBoard.complete = true;
			gameBoard.playerWin = false;
		}
	}

	drawBoard(gameBoard);
	if (gameBoard.playerWin) {
		std::cout << "Congratulations! You Win!";
	}
	else {
		std::cout << "Better Luck Next Time!";
	}

	return 0;
}