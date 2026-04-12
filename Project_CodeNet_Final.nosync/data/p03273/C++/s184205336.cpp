#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<bool> dr(H, true), dc(W, true);
  vector<string> L(H);
  for (int i = 0; i < H; i++) {
    cin >> L[i];
    for (int j = 0; j < W; j++) {
      if (L[i][j] == '#') {
        dr[i] = false;
        dc[j] = false;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (dr[i]) continue;
    for (int j = 0; j < W; j++) {
      if (dc[j]) continue;
      cout << L[i][j];
    }
    cout << endl;
  }
}