#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
void displayBoardFunc(int CX, int CY);
char newdisplay = ' ';
int main (){
	
	int boardx = 1;
	int boardy = 1;
	int X;
	int Y;
	
	bool playing = true;
	
	int *BX;
	BX= new int [boardx];
	
	
	int *BY;
	BY= new int [boardy];
	
	char cord = 'a';
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
	
	
	//newdisplay = '.';	
	displayBoardFunc(boardx,boardy);
	
	
	
	
	//prints blank board
	while(playing){
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
		//displayB.close();
	//asks for cords to check
	
		cout << "Please enter the coordinates you would like to check: " << endl;
		cout << "Enter X: ";
		cin >> X;
		cout << "Enter Y: ";
		cin >> Y;
		
		
		ifstream gameB;
		gameB.open("gameboard.txt");
		if(gameB.fail()){
			cout << "Unable to open file gameboard.txt" << endl;
			exit(1);
		}
		if (gameB.is_open()){
			cord = board[X][Y];
			//cout << cord;
			if (cord == '.'){
				//displayBoardFunc(X,Y);
				ofstream displayB;
				displayB.open("displayboard.txt");
				if(displayB.fail()){
				cout << "Unable to open file displayboard.txt" << endl;
				exit(1);
				}
				displayB << 'b';
			}
			
			//cout << cord;
		}
	}
	//updates board
	
}

void displayBoardFunc(int CX, int CY){
	
	ofstream display;
		display.open("displayboard.txt");
		if(display.fail()){
			cout << "Unable to open file displayboard.txt" << endl;
			exit(1);
		}
		for(int i=0; i < CX; i++){
			
			for(int j=0; j < CY; j++){
				
				display << '.';
				
			}
			display << endl;
		}
		
}