#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  
  vector<int> h(H, 0), w(W, 0);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '#') {
        h[i]++; w[j]++;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    if (h[i] == 0) continue;
    for (int j = 0; j < W; j++) {
      if (w[j] == 0) continue;
      cout << a[i][j];
    }
    cout << endl;
  }
}