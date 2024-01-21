#include <iostream>

using namespace std;

//constant variables
const int ROW = 6;
const int COLUMN = 7;

bool ColumnIsFull(int Grid[ROW][COLUMN], int column){
  bool colIsFull = true;
  
  for(int i = ROW - 1 ; i >= 0; i--) {
    if(Grid[i][column - 1] == 0){
      colIsFull = false;
      break;
    }
  }
  return colIsFull;
}

int GetPlayerInput(int Grid[ROW][COLUMN], int playerNum){
  int column;
  
  cout << "Player " << playerNum << ", please enter a column number (1-7): ";
  
  cin >> column;
  cout << endl;
  
  while(column < 1 || column > 7 || cin.bad() || ColumnIsFull(Grid, column)){
    cout << "Input is invalid. Please enter a column number (1-7): ";
    cin.clear();
    cin.ignore(40, '\n');
    cin >> column;
  }
  return column;
}

//function for display the grid
void displayGrid(int Grid[ROW][COLUMN]){
  for (int i = 0; i < ROW; i++) {
    
    for (int j = 0; j < COLUMN; j++){
      if (Grid[i][j] == 0) {
        cout << "* ";
      }
      else if (Grid[i][j] == 1){
        cout << "X ";
      }
      else if(Grid[i][j] == 2){
        cout << "O ";
      }
      //cout << Grid[i][j] << " ";
    }
    cout << endl;
  }
}
//function for spawning the pieces
void spawnP(int Grid[ROW][COLUMN], int column, int player) {
  for (int i = ROW - 1; i >= 0; i--){
    if (Grid[i][column-1] == 0){
      //player pick column
      //input goes to first place that isnt full
      Grid[i][column-1] = player;
      return;
    }
  }
}

//function for checking if 4 in a row
int inARow(int Grid[ROW][COLUMN]) {
  //check for horizontal
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COLUMN-3; j++) {
        if (Grid[i][j] == Grid[i][j+1] && Grid[i][j+1] == Grid[i][j+2] && Grid[i][j+2] == Grid[i][j+3] && Grid[i][j] != 0) {
          return Grid[i][j];
        }  
    }
  }
  //check for vertical
  for (int i = 0; i < COLUMN; i++) {
    for (int j = 0; j < ROW-3; j++) {
        if (Grid[j][i] == Grid[j+1][i] && Grid[j+1][i] == Grid[j+2][i] && Grid[j+2][i] == Grid[j+3][i] && Grid[j][i] != 0) {
          return Grid[j][i];
        }
    }
  }
  //check for diagonal
  for (int i = 0; i < ROW-3; i++) {
    for (int j = 0; j < COLUMN-3; j++) {
        if (Grid[i][j] == Grid[i+1][j+1] && Grid[i+1][j+1] == Grid[i+2][j+2] && Grid[i+2][j+2] == Grid[i+3][j+3] && Grid[i][j] != 0) {
          return Grid[i][j];
        }
    }
  }
  for (int i = 0; i < ROW-3; i++) {
    for (int j = 3; j < COLUMN; j++) {
        if (Grid[i][j] == Grid[i+1][j-1] && Grid[i+1][j-1] == Grid[i+2][j-2] && Grid[i+2][j-2] == Grid[i+3][j-3] && Grid[i][j] != 0) {
          return Grid[i][j];
        }
    }
  }
  return 0;
}

int main() {
  int Grid[ROW][COLUMN] = {};

  bool GameState = true;
  int turnCounter = 0;

  while(GameState && turnCounter <= 42) {
    displayGrid(Grid);
    cout << endl;
    int playerNum = 1;
    int column;
    
    //prints out the grid
    //asks player 1 for input
    //validate input
    column = GetPlayerInput(Grid, playerNum);
    
    //update grid
    spawnP(Grid, column, playerNum);
    //checks if player 1 won
    if(inARow(Grid) != 0) {
      displayGrid(Grid);
      cout << endl;
      cout << "Player 1 wins!" << endl;
      GameState = false;
      break;
    }
    displayGrid(Grid);
    cout << endl;
    playerNum = 2;
    //asks player 2 for input
    //validate input
    column = GetPlayerInput(Grid, playerNum);
    //update grid
    spawnP(Grid, column, playerNum);
    //checks if player 2 won
    if(inARow(Grid) != 0) {
      displayGrid(Grid);
      cout << endl;
      cout << "Player 2 wins!" << endl;
      GameState = false;
    }
    ++turnCounter;
    
    if(turnCounter == 42){
      GameState = false;
    }
  }

  //* * * * * * *
  //* * * * * * *
  //* * * * * * *
  //* * * * * * *
  //* * * * * * *
  //* * * * * * *
  //std::cout << "Goodbye World!\n";
return 0;
}
