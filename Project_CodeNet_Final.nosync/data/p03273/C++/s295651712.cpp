#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid.at(i).at(j);
    }
  }
  
  vector<int> yoko,tate;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '#') {
        break;
      }
      if (j == W - 1) {
        yoko.push_back(i);
      }
    }
  }
  
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (grid.at(i).at(j) == '#') {
        break;
      }
      if (i == H - 1) {
        tate.push_back(j);
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (count(yoko.begin(),yoko.end(),i)) {
      continue;
    }
    for (int j = 0; j < W; j++) {
      if (count(tate.begin(),tate.end(),j)) {
        continue;
      }
      cout << grid.at(i).at(j);
    }
    cout << endl;
  }
}