// Functions definition

#include <iostream>
#include <string>
#include <vector>

void intro() {

	std::cout << "\n================== Tic-Tac-Toe ==================\n";
	std::cout << "First to place 3 of their marks diagonal, horizontal or vertical is the winner!\n";
	std::cout << "Player 1: x\nPlayer 2: o\n\n";
	
}

// Initialize board with spaces
void clear_board(char (*board)[3]) {
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
	
}

void draw(char (*board)[3]) {
	
	// first 2 rows
	for (int i = 0; i < 2; i++) {
		std::cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
		std::cout << "-----------\n";
	}
	// 3rd row
	std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";

}

bool turn(char (*board)[3], std::string player, char mark) {
	
	int cell; // cell where to put the mark
	std::cout << player + ", your turn: ";
	std::cin >> cell;
	std::cout << "\n";
	
	int i = (cell-1) / 3;
	int j = (cell-1) % 3;
	
	if (board[i][j] != ' ') {
		return false;
	} else {
		board[i][j] = mark;
		return true;
	}
}

// winning combinations
int win_combs[8][3][2] = {
	{{0, 0}, {1, 1}, {2, 2}},
	{{2, 0}, {1, 1}, {0, 2}},
	{{0, 0}, {1, 0}, {2, 0}},
	{{0, 1}, {1, 1}, {2, 1}},
	{{0, 2}, {1, 2}, {2, 2}},
	{{0, 0}, {0, 1}, {0, 2}},
	{{1, 0}, {1, 1}, {1, 2}},
	{{2, 0}, {2, 1}, {2, 2}}
};

char is_winner(char (*board)[3]) {

	for (int i = 0; i < 8; i++) {
		std::vector<char> marks;
		
		for (int j = 0; j < 3; j++) {
			int x = win_combs[i][j][0], y = win_combs[i][j][1];
			marks.push_back(board[x][y]);
		}
		
		// winner in the game
		if (marks[0] == marks[1] && marks[0] == marks[2]) {
			return marks[0];
		}
		
		/*
		std::cout << win_combs[i][0][0] << "" << win_combs[i][0][1] << " ";
		std::cout << win_combs[i][1][0] << "" << win_combs[i][1][1] << " ";
		std::cout << win_combs[i][2][0] << "" << win_combs[i][2][1] << " ";
		std::cout << "\n";
		*/
	}
	
	return ' ';

}

void show_winner(char c, std::string player1, std::string player2) {

	if (c == 'x') {
		std::cout << "Winner: " + player1 + "\n";
	} else {
		std::cout << "Winner: " + player2 + "\n";
	}
}


