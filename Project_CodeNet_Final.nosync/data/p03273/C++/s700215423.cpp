#include <bits/stdc++.h>
using namespace std;

const char white_cell = '.';
const char black_cell = '#';

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a[i];
  }

  // true: 黒マス
  vector<vector<bool>> flags(H, vector<bool>(W, true));

  // 横の圧縮
  for (int i = 0; i < H; i++) {
    // 横一列見る。途中に黒マスがあったらそれ以上見る意味がない
    bool flag = true;
    for (int j = 0; j < W; j++) {
      if (a[i][j] == black_cell) {
        flag = false;
        break;
      }
    }
    if (flag) {
      for (int j = 0; j < W; j++) {
        flags[i][j] = false;
      }
    }
  }

  // 縦の圧縮
  for (int i = 0; i < W; i++) {
    bool flag = true;
    for (int j = 0; j < H; j++) {
      if (a[j][i] == black_cell) {
        flag = false;
        break;
      }
    }
    if (flag) {
      for (int j = 0; j < H; j++) {
        flags[j][i] = false;
      }
    }
  }

  for (int i = 0; i < flags.size(); i++) {
    string row;
    for (int j = 0; j < flags[i].size(); j++) {
      if (flags[i][j]) {
        row += a[i][j];
      }
    }
    if (!row.empty()) {
      cout << row << endl;
    }
  }
  cout << endl;
}