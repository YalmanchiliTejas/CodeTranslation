#include <bits/stdc++.h>
using namespace std;

int multi(vector<int> a) {
  int result = 1;
  for (int x : a) {
    result *= x;
  }
  return result;
}

int main() {
  int H, W;
  cin >> H >> W;
  char wh = '.', bl = '#';
  vector<vector<char>> cell(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> cell.at(i).at(j);
    }
  }

  vector<bool> rm_row(H, true);
  vector<bool> rm_col(W, true);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (cell.at(i).at(j) == bl) {
        rm_row.at(i) = false;
        break;
      }
    }
  }
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (cell.at(i).at(j) == bl) {
        rm_col.at(j) = false;
        break;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (rm_row.at(i)) continue;
    for (int j = 0; j < W; j++) {
      if (rm_col.at(j)) continue;
      cout << cell.at(i).at(j);
    }
    cout << endl;
  }
}
