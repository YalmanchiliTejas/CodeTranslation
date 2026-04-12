#include <bits/stdc++.h>

using namespace std;

typedef vector<int> v;
typedef vector<vector<int>> vv;

int main() {
  int W, H;
  cin >> H >> W;
  vector<int> h(H, 0);
  vector<int> w(W, 0);
  vector<vector<char>> t(H, vector<char>(W));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> t[i][j];
      if (t[i][j] == '#') h[i] = w[j] = 1;
    }
  }
  for (int i = 0; i < H; ++i) {
    if (h[i] == 0) continue;
    for (int j = 0; j < W; ++j) {
      if (w[j] == 0) continue;
      cout << t[i][j];
    }
    cout << endl;
  }
}