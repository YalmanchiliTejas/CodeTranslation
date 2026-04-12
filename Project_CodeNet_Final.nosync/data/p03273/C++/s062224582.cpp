#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  vector<bool> row_removed(H, true);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (A[i][j] == '#') {
        row_removed[i] = false;
        break;
      }
    }
  }
  vector<bool> col_removed(H, true);
  for (int j = 0; j < W; ++j) {
    for (int i = 0; i < H; ++i) {
      if (A[i][j] == '#') {
        col_removed[j] = false;
        break;
      }
    }
  }
  for (int i = 0; i < H; ++i) {
    if (row_removed[i]) continue;
    for (int j = 0; j < W; ++j) {
      if (col_removed[j]) continue;
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}
