#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  char b[H][W];
  // vector<int> b[H][W];

  bool x[H];  // i行目（0~）は削除可能か
  bool y[W];  // i列目（0~）は削除可能か

  for (int i = 0; i < H; i++) {
    x[i] = true;
  }
  for (int i = 0; i < W; i++) {
    y[i] = true;
  }

  char tmp;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> tmp;
      b[i][j] = tmp;
      if (tmp == '#') {
        x[i] = false;
        y[j] = false;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (x[i]) {
      continue;
    }
    for (int j = 0; j < W; j++) {
      if (y[j]) {
        // pass
      } else {
        cout << b[i][j];
      }
    }
    cout << "\n";
  }
}