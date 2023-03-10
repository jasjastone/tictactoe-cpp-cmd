/**
Project Author Jasjastone
Made with love
You may use the project as you wish no string attached
*/
#include<iostream>
#include "gameboard.cpp"
using namespace std;

int main(){
	char doyouwanttoplay = ' ';

	cout << "Welcome to Tic Tac Toe game\n" << endl;
	cc:
    cout << "Enter Y if you choose to play and N if you want quit: \n";
    cin >> doyouwanttoplay;

    if(doyouwanttoplay =='Y'||doyouwanttoplay =='y'){
    	GameBoard* gameBoard = new GameBoard(9,6);
		gameBoard->input(doyouwanttoplay);
		gameBoard->play();
	}
	else if(doyouwanttoplay =='N'||doyouwanttoplay =='n'){
	    return 0;
	}
	else{
		cout << "The choice entered is neither Y or N. \nPlease enter the right choice: \n";
        goto cc;

	}
}





