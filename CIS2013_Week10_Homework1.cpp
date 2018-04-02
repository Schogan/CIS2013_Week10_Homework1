#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main (){
	
	int boardx = 1;
	int boardy = 1;
	
	
	int *BX;
	BX= new int [boardx];
	
	
	int *BY;
	BY= new int [boardy];
	
	char board [10][10];
	
	int mines = 1;
	
	int *m;
	m= new int[mines];
	
	//Ask for board size and number of mines
	cout << "Please enter the size of board you want:" << endl;
	cout << "X: ";
	cin >> boardx;
	cout << "Y: ";
	cin >> boardy;
	cout << "How many mines would you like?" << endl;
	cin >> mines;
	//creates game board and stores info
	
	ofstream game;
	game.open("gameboard.txt");
	if(game.fail()){
		cout << "Unable to open file gameboard.txt" << endl;
		exit(1);
	}
	
	
	for(int i=0; i < boardx; i++){
		
		for(int j=0; j < boardy; j++){
			
			game << '.';
			
		}
		game << endl;
	}
	
	ofstream display;
	display.open("displayboard.txt");
	if(display.fail()){
		cout << "Unable to open file displayboard.txt" << endl;
		exit(1);
	}
	for(int i=0; i < boardx; i++){
		
		for(int j=0; j < boardy; j++){
			
			display << '.';
			
		}
		display << endl;
	}
	
	
	
	
	
	//prints blank board
	ifstream displayB;
	displayB.open("displayboard.txt");
	if(displayB.fail()){
		cout << "Unable to open file displayboard.txt" << endl;
		exit(1);
	}
	for(int i=0; i < boardx; i++){
		
		for(int j=0; j < boardy; j++){
			displayB >> board[i][j];
		}
		
	}
	//display board
	for(int i=0; i < boardx; i++){
		
		for(int j=0; j < boardy; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
	//asks for cords to check
	//cout << "Please enter the coordinates you would like to check (X/Y): " << endl;
	//updates board
	
}