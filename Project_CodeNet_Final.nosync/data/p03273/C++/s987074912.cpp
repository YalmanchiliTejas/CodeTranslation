#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  char a[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> okLineH, okLineW;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '#') {
        okLineH.push_back(i);
        break;
      }
    }
  }
  cout << endl;
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (a[j][i] == '#') {
        okLineW.push_back(i);
        break;
      }
    }
  }
  cout << endl;

  for(int i = 0; i < okLineH.size(); i++) {
    for(int j = 0; j < okLineW.size(); j++) {
      cout << a[okLineH[i]][okLineW[j]];
    }
    cout << endl;
  }

  return 0;
}