/*Project author @jasjastone*/

#include<iostream>
using namespace std;

class GameBoardPosition{
	public:
		int row;
		int column;
		GameBoardPosition(int row,int column){
			this->row = row;
			this->column = column;
		}

};

class GameBoard{
	public:
		int rowSize;
		char player1;
		char player2;
		int columnSize;
		char board[6][9];
		int wonSize = 4;
		GameBoard(int rowSize,int columnSize){
			this->rowSize= rowSize;
			this->columnSize= columnSize;
			this->board[this->rowSize][this->columnSize];
			for (int i = 0; i<this->rowSize; i++)
		    {
		      for (int j = 0; j<this->columnSize; j++){
		      this->board [i][j] = ' ';
			  }
		    }
			cout<<"\nHere is our game format\n";
			this->printGameBoard();
			}

//	place the token to the board
	bool placeToken(GameBoardPosition* pos, char token){
		if(pos->row >= 0 && pos->row < this->rowSize && this->columnSize >= 0 && pos->column <= this->columnSize && this->board[pos->row][pos->column] == ' '){
        this->board[pos->row][pos->column] = token;
        return true;
    }
    else if(this->board[pos->row][pos->column] != ' ' && pos->row >= 0 && pos->row < this->rowSize && pos->column >= 0 && pos->column <= this->columnSize){
        cout << "That place is already occupied, please try again\n" << endl;
        return false;
    }
    else if(pos->row >= this->rowSize || pos->column >= this->columnSize){
        cout << "\nThat is out of bounds!\nTry again\n" << endl;
        return false;
    }
    else
        return false;
	}

//	check if the board is full no more move to play
	bool isFull(){
		bool isfull = true;
		for (int i = 0; i<this->rowSize; i++)
		    {
		      for (int j = 0; j<this->columnSize; j++){
		      if(this->board [i][j] == ' ' ){
		      	isfull = false;
			  }
			  }
		    }
		return isfull;
	}

//	check if there is a winner
	bool checkWinner(GameBoardPosition* pos, char token)
	{
//		 || this->diagonalWin(pos,token)
		if(this->diagonalWin(pos,token) || this->horizontalWin(pos,token) || this->verticalWin(pos,token)){
			return true;
		}
		return false;
	}

//	check if the player has won horizontally
	bool horizontalWin(GameBoardPosition* pos, char token){
		char tokenBoard = this->board[pos->row][pos->column];
		int consecutive = 1;
//		checking from left to right
	    for (int i = pos->column; i < this->columnSize; i++){
	        if (this->board[pos->row][i] == tokenBoard){
				if(consecutive == 4)
				{
	            	return true;
				}
				consecutive++;

	        }
	        else
	            {
	            	break;
				}
	    }
	    consecutive = 1;
	    // Checking for horizontal win to the left
	    for (int i = pos->column; i >= 0; i--){
	        if (this->board[pos->row][i] == tokenBoard){
				if (consecutive == 4)
	                return true;
	            consecutive++;


	        }
	        else
	            break;
	    }
	    return false;
	}

//	check if the player has won vertically
	bool verticalWin(GameBoardPosition* pos,char token){
    int consecutive = 1;
    for (int i = pos->row; i >= 0; i--){
        if (this->board[i][pos->column] == token){
            if (consecutive == 4)
                return true;
            consecutive++;
        }
        else
            break;
    }
    consecutive = 1;
    for (int i = pos->row; i < this->rowSize; i++){
        if (this->board[i][pos->column] == token){
            if (consecutive == 4)
                return true;
            consecutive++;
        }
        else
            break;
    }

    return false;

	}

//	check if the player has won diagonally
	bool diagonalWin (GameBoardPosition* pos, char token){
    int consecutive = 1;
    for (int i = pos->row, j = pos->column; i >= 0 && j < this->columnSize; i--, j++){
        if (board[i][j] == token){

            if (consecutive == 4)
                return true;
            consecutive++;
        }
        else
            break;
    }
    consecutive = 1;
    for (int i = pos->row, j = pos->column; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == token){
            if (consecutive == 4)
                return true;
            consecutive++;
        }
        else
            break;
    }
    consecutive = 1;
    for (int i = pos->row, j = pos->column; i < this->rowSize && j < this->columnSize; i++, j++){
        if (board[i][j] == token){
            if (consecutive == 4)
                return true;
            consecutive++;
        } else
            break;
    }
    consecutive = 1;
    for (int i = pos->row, j = pos->column; i < this->rowSize && j >= 0; i++, j--){
        if (board[i][j] == token){
            if (consecutive == 4)
                return true;
            consecutive++;
        }
        else
            break;
    }
    return false;
	}
//	get the token of the position required
	char getToken(GameBoardPosition* pos){
		return this->board[pos->row][pos->column];
	}

//	print the current state of the gameboard
	void printGameBoard(){
	for(int i = 0; i < this->columnSize;i++){
		if(i==0){
			cout << " |"<<i;
		}
		else{
		cout << "|"<<i;
		}
	}
	cout<<endl;
    for(int i = 0; i < this->rowSize; i++)
    {
        cout << i << "|";
        for(int j = 0; j < this->columnSize; j++)
            cout << this->board [i][j] << "|";
        cout << endl;
    }
	}

//	get user input and assign a player tokens
	void input (char choice){
    if(choice == 'Y'||choice=='y'){
			do{
				cout<<"\nPlayer 1, Select a token. Either X or O: \n";
				cin >>this->player1;
				if(this->player1 == 'X'||this->player1 == 'x'){
					this->player2 ='O';
					cout <<"\nPlayer 2, Your token is, "<< this->player2 << endl;

				}
				else if(this->player1 == 'O'||this->player1 == 'o'){
					this->player2 = 'X';
					cout <<"Player 2, Your token is, "<< this->player2 << endl;
				//	initializer (board,Size);
				}
				else{
					cout << "The token either X or O, Try again\n" << endl;
                }
            }while (this->player1 != 'X' &&this->player1 != 'x' && this->player1 != 'O' && this->player1 != 'o');
        }

    else if (choice == 'N'||choice=='n'){
    		cout << "Bye Bye!";

	}
}

// function to run the game
	void play(){
		restart:
    bool player1Turn = true;
    bool gameOver = false;
    bool player1win = false;
    bool player2win = false;
    char playagainchoice;
        do{
            if (player1Turn){
			vc:
				GameBoardPosition* positions = new GameBoardPosition(0,0);
                cout << "\nPlayer 1, enter the 'row' and 'column' to place your token: \n";
                cout<<"Start with a row ";
				cin >> positions->row;
                cout<<"\n Now Enter Column ";
				cin>>positions->column;

                if (this->placeToken(positions,this->player1))
                    player1Turn = !player1Turn;
                player1win = this->checkWinner(positions,this->player1);
            }
            else{
            	GameBoardPosition* positions = new GameBoardPosition(0,0);
                cout << "\nPlayer 2, enter the 'row' and 'column' to place your token: \n";
                cout<<"Start with a row ";
				cin >> positions->row;
                cout<<"\n Now Enter Column ";
				cin>>positions->column;

                if (this->placeToken(positions,this->player2)){
                	player1Turn = !player1Turn;
				}
                player2win = this->checkWinner(positions, this->player2);
            }
            gameOver = this->isFull();

            this->printGameBoard();

            if(player1win){
                cout << "Player one won" << endl;
                break;
            }
            else if(player2win){
                cout << "Player two won" << endl;
                break;
            }
        }while (!gameOver);

        if (gameOver){
            cout << "Game over!\n!!! It's a draw!!!" << endl;
        }
        else if (player1win || player2win){
            cout <<"Thanks for playing Tic-Tac-Toe!" << endl;
    		cout << "Do you wish to play again? (Y/N): ";
    		cin>>playagainchoice;
			if(playagainchoice == 'Y'|| playagainchoice=='y'){
				this->resetGameBoard();
				goto restart;
			}
        }
}
// this function used to reset the game when its over
void resetGameBoard(){
	for (int i = 0; i<this->rowSize; i++)
		    {
		      for (int j = 0; j<this->columnSize; j++){
		      this->board [i][j] = ' ';
			  }
		    }
}
};

