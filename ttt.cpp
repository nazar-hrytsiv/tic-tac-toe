// Popular game Tic-Tac-Toe 3x3

#include <iostream>
#include <string>
#include "ttt_func.hpp"

int main() {
	
	intro();
	
	// Prompt players
	std::string player1, player2;
	std::cout << "Player 1: ";
	std::cin >> player1;
	std::cout << "Player 2: ";
	std::cin >> player2;
	
	// Game board 3x3
	char board[3][3] = {0};
	
	// Clear board
	clear_board(board);
	
	// Draw board
	draw(board);
	
	// start game
	int moves = 0; // count of players moves - 9 max.
	char c; // indicates if the game has winner
	while (moves < 8) {
		while (!turn(board, player1, 'x')) {}
		draw(board);
		
		c = is_winner(board);
		if (c != ' ') {
			show_winner(c, player1, player2);
			return 0;
		}
		
		moves++;
		
		while (!turn(board, player2, 'o')) {}
		draw(board);
		
		c = is_winner(board);
		if (c != ' ') {
			show_winner(c, player1, player2);
			return 0;
		}
		
		moves++;
	}
	// last move
	while (!turn(board, "pavlo", 'x')) {}
	draw(board);
	
	return 0;
}