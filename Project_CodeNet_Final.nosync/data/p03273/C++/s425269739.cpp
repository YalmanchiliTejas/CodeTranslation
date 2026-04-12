#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> grid(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid.at(i).at(j);
    }
  }
  
  // 残す行，列
  vector<bool> leave_row(H, false);
  vector<bool> leave_col(W, false);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '#') {
        leave_row.at(i) = true;
        leave_col.at(j) = true;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (leave_row.at(i)) {
      for (int j = 0; j < W; j++) {
        if (leave_col.at(j)) {
          cout << grid.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}