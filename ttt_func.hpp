// Functions declaration

#include <string>

void intro();
void clear_board(char (*board)[3]);
void draw(char (*board)[3]);
bool turn(char (*board)[3], std::string player, char mark);
char is_winner(char (*board)[3]);
void show_winner(char c, std::string player1, std::string player2);