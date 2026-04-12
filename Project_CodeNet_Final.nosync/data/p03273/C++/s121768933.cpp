#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W; cin >> H >> W;
  vector<vector<char>> grids(H, vector<char>(W, 0));
  vector<vector<bool>> isRemained(H, vector<bool>(W, true));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grids.at(i).at(j);
    }
  }
  
  for (int i = 0; i < H; i++) {
    bool isAllWhite = true;
    for (int j = 0; j < W; j++) {
      if (grids.at(i).at(j) == '#') {
        isAllWhite = false;
        break;
      }
    }
    if (isAllWhite) {
      for (int j = 0; j < W; j++) isRemained.at(i).at(j) = false;
    }
  }
  
  for (int i = 0; i < W; i++) {
    bool isAllWhite = true;
    for (int j = 0; j < H; j++) {
      if (grids.at(j).at(i) == '#') {
        isAllWhite = false;
        break;
      }
    }
    if (isAllWhite) {
      for (int j = 0; j < H; j++) isRemained.at(j).at(i) = false;
    }
  }
  
  for (int i = 0; i < H; i++) {
    bool isNoneRow = true;
    for (int j = 0; j < W; j++) {
      if (isRemained.at(i).at(j)) {
        cout << grids.at(i).at(j);
        isNoneRow = false;
      }
    }
    if (!isNoneRow) cout << endl;
  }
}