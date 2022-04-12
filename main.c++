#include<iostream>
#include<stdlib.h>
using namespace std;

//Globals
char turn='X';
int b[9]={0};
int row;
int col;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int key;
bool draw = false;

void display_board(){
   //Display
  system("cls");
   cout<<"\t T i c k  T a c k  T o e  G a m e\n";
   cout<<"\n\tPlayer1[x] \n\tPlayer2[O]\n";

   cout<<"\n\t\t\t     |     |     ";
   cout<<"\n\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  ";
   cout<<"\n\t\t\t_____|_____|_____";
   cout<<"\n\t\t\t     |     |     ";
   cout<<"\n\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  ";
   cout<<"\n\t\t\t_____|_____|_____";
   cout<<"\n\t\t\t     |     |     ";
   cout<<"\n\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  ";
   cout<<"\n\t\t\t     |     |     \n";
}

void player_turn(){

  if(turn=='X'){
    cout<<"Player1 [X] turn: \n";
  }

  if(turn=='O'){
    cout<<"Player2 [O] turn: \n";
  }

  cin>>key;




   switch(key){
     case 1:
           row=0;
           col=0;
           break;
     case 2:
           row=0;
           col=1;
           break;
     case 3:
           row=0;
           col=2;
           break;
     case 4:
           row=1;
           col=0;
           break;
     case 5:
           row=1;
           col=1;
           break;
     case 6:
           row=1;
           col=2;
           break;
     case 7:
           row=2;
           col=0;
           break;
     case 8:
           row=2;
           col=1;
           break;
     case 9:
           row=2;
           col=2;
           break;

    default:
    cout<<"Invalid Choice"<<endl;
    break;
 }

 if(turn=='X' and board[row][col]!='X' and board[row][col]!='O'){
  board[row][col]='X';
  turn='O';
 }

 else if(turn=='O' and board[row][col]!='X' and board[row][col]!='O'){
  board[row][col]='O';
  turn='X';
 }

 else{
  cout<<"Box allready filled' \nPlease enter another value:\n\n\n";
  player_turn();
 }
}

bool gameover(){
  //case 1
  for(int i=0;i<3;i++){
    if(board[i][0]==board[i][1] and board[i][0]==board[i][2]){
      return false;
    }
    if(board[0][i]==board[1][i] and board[0][i]==board[2][i]){
      return false;
    }
  }
  if(board[0][0]==board[1][1] and board[0][0]==board[2][2]){
      return false;
    }
  if(board[0][2]==board[1][1] and board[0][2]==board[2][0]){
      return false;
    }

  //Case 2
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(board[i][j]!='X' and board[i][j]!='O'){
        return true;
      }
    }
  }

  draw = true;
  return false;
}

int main(){

  //Logic


while(gameover()){
   display_board();
   player_turn();
   gameover();
}

if(turn='X' and draw==false){
  cout<<"----------------------Congratulations Player1 won----------------------------"<<endl;
  cout<<"\n\n-------------------------------Player2 Lose------------------------------------"<<endl;
}

else if(turn='O' and draw==false){
  cout<<"----------------------Congratulations Player2 won----------------------------"<<endl;
  cout<<"\n\n-------------------------------Player1 Lose------------------------------------"<<endl;
}

else{
  cout<<"-------------------------------------GAME DRAW-----------------------------------"<<endl;
}

  return 0;
}
