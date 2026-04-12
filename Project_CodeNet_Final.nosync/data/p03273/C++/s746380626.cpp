#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> board(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> board.at(i).at(j);
    }
  }
  
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (board.at(i).at(j) == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }
     
  for (int i = 0; i < H; i++) {
    if (row[i]) {
      for (int j = 0; j < W; j++) {
         if (col[j]) {
         	cout << board[i][j];
       	 }
      }
      cout << endl;
    }
  }
  
}