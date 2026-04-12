#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> pix(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> pix.at(i).at(j);
    }
  }
  
  vector<bool> is_row_whight(H);
  for (int i = 0; i < H; i++) {
    is_row_whight.at(i) = true;
  }
  
  vector<bool> is_col_whight(W);
  for (int i = 0; i < W; i++) {
    is_col_whight.at(i) = true;
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (pix.at(i).at(j) == '#') {
        is_row_whight.at(i) = false;
        is_col_whight.at(j) = false;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (is_row_whight.at(i)) {
      continue;
    }
    for (int j = 0; j < W; j++) {
      if (!is_col_whight.at(j)) {
        cout << pix.at(i).at(j);
      }
      if (j == W - 1) {
        cout << endl;
      }
    }
  }
}