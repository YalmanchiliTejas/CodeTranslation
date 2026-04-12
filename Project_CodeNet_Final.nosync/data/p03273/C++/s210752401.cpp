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
  
  vector<int> row(H);
  vector<int> col(W);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '#') {
        row.at(i) = 1;
        col.at(j) = 1;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    bool rowflag = false;
    for (int j = 0; j < W; j++) {
      if (row.at(i) == 1 && col.at(j) == 1) {
        cout << grid.at(i).at(j);
        rowflag = true;
      }
    }
    if (rowflag) {
      cout << endl;
    }
  }
}
