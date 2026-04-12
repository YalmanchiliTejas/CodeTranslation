#include <bits/stdc++.h>
using namespace std;



int main(){
  int H,W; cin >> H >> W;
  bool board_check[H][W];
  for(int i=0;i<H;i++){for(int j=0;j<W;j++) {board_check[i][j]=true;}}
  string board[H];
  for(int i=0;i<H;i++){cin >> board[i];}
  
  for(int i=0;i<H;i++){
    bool flag = false;
    for(int j=0;j<W;j++){
      flag += (board[i][j]=='#');
    }
    if(!flag){
      for(int j=0;j<W;j++){
        board_check[i][j] = false;
      }
    }
  }
  
  for(int j=0;j<W;j++){
    bool flag = false;
    for(int i=0;i<H;i++){
      flag += (board[i][j]=='#');
    }
    if(!flag){
      for(int i=0;i<H;i++){
        board_check[i][j] = false;
      }
    }
  }
  
  for(int i=0;i<H;i++){
    bool line_f = false;
    for(int j=0;j<W;j++){
      if(board_check[i][j]){
        cout << board[i][j];
        line_f = true;
      }

    }
    if(line_f){
      cout << endl;
    }
  }
  
  
}