#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w; cin >> h >> w;
  vector<string> board(h);
  for (auto& e: board) cin >> e;

  vector<bool> rowIncludeSharp(h), colIncludeSharp(w);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '#') {
        rowIncludeSharp[i] = true;
        colIncludeSharp[j] = true;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    if (rowIncludeSharp[i]) {
      for (int j = 0; j < w; j++) {
        if (colIncludeSharp[j]) {
          cout << board[i][j];
        }
      }
      cout << endl;;
    }
  }
}