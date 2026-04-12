#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  vector<vector<char> > grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }
  vector<bool> yoko(H, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '#') {
        yoko[i] = true;
        break;
      }
    }
  }
  vector<bool> tate(W, false);
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (grid[j][i] == '#') {
        tate[i] = true;
        break;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (yoko[i] && tate[j]) {
        cout << grid[i][j];
      }
    }
    if (yoko[i]) {
      cout << endl;
    }
  }
}