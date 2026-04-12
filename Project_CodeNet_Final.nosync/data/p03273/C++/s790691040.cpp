#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  string board[110];
  for (int i = 0; i < h; i++) {
      cin >> board[i];
  }

  bool x[110] = {false};
  bool y[110] = {false};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '#') {
        x[i] = true;
        y[j] = true;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    if (x[i]) {
      for (int j = 0; j < w; j++) {
        if (y[j]) {
          cout << board[i][j];
        }
      }
      cout << endl;
    }
  }
  return 0;
}
