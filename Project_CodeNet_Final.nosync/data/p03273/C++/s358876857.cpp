#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  for (int i=0; i < H; i++) {
    cin >> grid.at(i);
  }
  vector<bool> rowmark(H,false), colmark(W,false);
  for (int i=0; i < H; i++) {
    bool flg = false;
    for (int j=0; j < W; j++) {
      if (grid.at(i).at(j) == '#') {
        flg = true;
      }
    }
    rowmark.at(i) = flg;
  }
    for (int i=0; i < W; i++) {
    bool flg = false;
    for (int j=0; j < H; j++) {
      if (grid.at(j).at(i) == '#') {
        flg = true;
      }
    }
    colmark.at(i) = flg;
  }
  for (int i=0; i < H; i++) {
    for (int j=0; j < W; j++) {
      if (rowmark.at(i) == true && colmark.at(j) == true) {
    cout << grid.at(i).at(j);
      }
    }
    if (rowmark.at(i) == true) {
    cout << endl;
    }
  }
}
