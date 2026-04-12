#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  char board[H][W];
  for (int i = 0; i < H; i++) {
	  for (int j = 0; j < W; j++) {
	    cin >> board[i][j];
      }
  }

  for (int i = 0; i < H; i++){
    int count = 0;
      for(int j = 0; j < W; j++){
        if(board[i][j] == '.' || board[i][j] == 'X') count++;
      }
       if(count == W){
          for(int j = 0; j < W; j++){
              board[i][j] = 'X';
          }
      }
  }

 for (int i = 0; i < W; i++){
    int count = 0;
      for(int j = 0; j < H; j++){
        if(board[j][i] == '.' || board[j][i] == 'X') count++;
      }
       if(count == H){
          for(int j = 0; j < H; j++){
              board[j][i] = 'X';
          }
      }
  }

  for (int i = 0; i < H; i++){
    int count2 = 0;
      for(int j = 0; j < W; j++){
        if(board[i][j] != 'X'){
          cout << board[i][j];
        }
        else count2++;
        if(j == W - 1 && count2 != W){
          cout << endl;
        }
      }
  }
}