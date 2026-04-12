#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> masme(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> masme[i][j];
    }
  }
  vector<bool> yoko(H, false);
  vector<bool> tate(W, false);

  for (int i = 0; i < H; i++) {
    bool black = false;
    for (int j = 0; j < W; j++) {
      if (masme[i][j] == '#') {
        black = true;
        break;
      }
    }
    if (!black) yoko[i] = true;
  }

  for (int i = 0; i < W; i++) {
    bool black = false;
    for (int j = 0; j < H; j++) {
      if (masme[j][i] == '#') {
        black = true;
        break;
      }
    }
    if (!black) tate[i] = true;
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (yoko[i] || tate[j]) continue;
      cout << masme[i][j];
    }
    if (!yoko[i]) cout << endl;
  }
}
