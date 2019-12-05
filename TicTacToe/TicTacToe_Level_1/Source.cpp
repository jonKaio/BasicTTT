/// A very basic minimalist Tic Tac Toe Game
/// All in a single file, not great.

#include <iostream>
#include <string>

std::string ** board;
int boardSize;
std::string player = " X ";

//Move these to the bottom after we're finished.

void MPrint(std::string _str) {
	std::cout << _str;
}
void MPrintNl(std::string _str) {
	std::cout << _str<<std::endl;
}



std::string Ask_String(std::string _str) {
	std::string rtn;
	MPrint(_str);
	std::getline(std::cin, rtn);
	return rtn;
}

int Ask_Int(std::string _str) {
	std::string rtns;
	MPrint(_str);
	std::getline(std::cin, rtns);
	
	return std::stoi(rtns);
}


 std::string PadString(std::string _str) {
	 std::string rtn = "00" + _str;
	 return rtn.substr(rtn.length()-3);
 }

 void InitBoard() {
	 int idx = 0;
	 board= new std::string*[boardSize];
	 for (int r = 0; r < boardSize; r++) {
		 board[r] = new std::string[boardSize];
		 for (int c = 0; c < boardSize; c++)
			 board[r][c] = PadString( std::to_string(idx++));
	 }
 }


 void PrintBoard() {
	 int idx = 0;
	 for (int r = 0; r < boardSize; r++) {
		 for (int c = 0; c < boardSize; c++)
			 MPrint(" | " + board[r][c]);
		 MPrintNl(" |");
	 }
 }

 bool CheckWin() {
	 bool win = false;
	 //Check Columns and rows
	 int rTotal = 0;
	 int cTotal = 0;
	 int d1Total = 0;
	 int d2Total = 0;
	 for (int i1 = 0; i1 < boardSize - 1; i1++) {
		 for (int i2 = 0; i2 < boardSize - 1; i2++) {
			 rTotal += board[i1][i2] == board[i1][i2 + 1] ? 1 : 0;
			 cTotal += board[i1][i2] == board[i1 + 1][i2] ? 1 : 0;
		 }
		 d1Total+= board[i1][i1] == board[i1+1][i1 + 1] ? 1 : 0;// \

		 d2Total+= board[ i1] [boardSize - i1 ]== board[ i1 ][boardSize - i1 -1] ? 1 : 0; // /


		 if (rTotal == boardSize - 1 || cTotal == boardSize - 1 || d1Total == boardSize - 1 || d2Total == boardSize - 1) win = true;
		 rTotal = 0;
		 cTotal = 0;
	 }

	 return win;
 }

int main() {
	MPrintNl("Hi there\nThis is a very basic Tic Tac Toe game.");
	MPrintNl("We are assuming a simple 2 player game for 'Player 1' & 'Player 2' taking turns.");
	MPrintNl("Player 1 gets to choose the size of the board.");
	boardSize = Ask_Int("How big should our square Tick Tac Toe board should be?");

	while (boardSize < 3 || boardSize>10) {
		MPrintNl("Choose a size between 3 and 10");
		boardSize = Ask_Int("How big should our square Tick Tac Toe board should be?");
	}

	InitBoard();
	bool running = true;
	int chosenPlace;

		PrintBoard();
	do {
		chosenPlace = -1;
		MPrint("\n\n\n\n\n");
		while (chosenPlace < 0) {
			chosenPlace = Ask_Int("Player "+player+", pick a cell for your X >");
			chosenPlace = board[chosenPlace / boardSize][chosenPlace % boardSize][0] != '0' ? -1 : chosenPlace;
		}
		board[chosenPlace / boardSize][chosenPlace % boardSize] = player;

		running = !CheckWin();
		PrintBoard();
		std::cout << (running ? "":"*********\n**********\nCongratulations " + player + "You have won.\n**********\n");
		player = player == " X " ? " O " : " X ";
		
	} while (running);




	

	while (true);
	return 0;
}