#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> v(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      v[i][j] = c;
    }
  }

  vector<bool> row(H, false), col(W, false);
  for (int i = 0; i < H; i++) {
    bool flag = true;
    for (int j = 0; j < W; j++) {
      if (v[i][j] != '.') {
        flag = false;
        break;
      }
    }
    if (flag) row[i] = true;
  }

  for (int j = 0; j < W; j++) {
    bool flag = true;
    for (int i = 0; i < H; i++) {
      if (v[i][j] != '.') {
        flag = false;
        break;
      }
    }
    if (flag) col[j] = true;
  }

  for (int i = 0; i < H; i++) {
    if (row[i]) continue;
    for (int j = 0; j < W; j++) {
      if (col[j]) continue;
      cout << v[i][j];
    }
    cout << endl;
  }
}
