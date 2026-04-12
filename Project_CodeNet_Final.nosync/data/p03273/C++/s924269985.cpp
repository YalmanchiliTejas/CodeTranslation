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
  vector<bool> row(H), col(W);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (A[i][j] == '#') {
        row[i] = col[j] = true;
      }
    }
  }
  for (int i = 0; i < H; ++i) {
    if (!row[i]) continue;
    for (int j = 0; j < W; ++j) {
      if (!col[j]) continue;
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}
