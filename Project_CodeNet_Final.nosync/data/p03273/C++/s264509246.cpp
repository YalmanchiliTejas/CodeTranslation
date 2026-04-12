#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  vector<bool> blank_rows(H, false);
  vector<bool> blank_columns(W, false);
  for (int i = 0; i < H; i++) {
    int count = 0;
    for (int j = 0; j < W; j++) {
      char input;
      cin >> input;
      if (input == '.') { count++; }
      grid.at(i).at(j) = input;
      if (j == W - 1 && count == W) { blank_rows.at(i) = true; }
    }
  }
  for (int i = 0; i < W; i++) {
    int count = 0;
    for (int j = 0; j < H; j++) {
      if (grid.at(j).at(i) == '.') { count++; }
      if (j == H - 1 && count == H) { blank_columns.at(i) = true; }
    }
  }
  for (int i = 0; i < H; i++) {
    if (blank_rows.at(i) == true) { continue; }
    for (int j = 0; j < W; j++) {
      if (blank_columns.at(j) == true) {
        if (j == W - 1) { cout << endl; }
        continue;
      }
      else if (j == W - 1) { cout << grid.at(i).at(j) << endl; }
      else { cout << grid.at(i).at(j); }
    }
  }
}