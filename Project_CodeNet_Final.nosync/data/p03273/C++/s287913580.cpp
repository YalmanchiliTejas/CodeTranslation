#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }

  vector<bool> isOutH(H), isOutW(W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        isOutH.at(i) = true;
        break;
      }
    }
  }
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (a.at(i).at(j) == '#') {
        isOutW.at(j) = true;
        break;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    if (!isOutH.at(i)) {
      continue;
    }
    for (int j = 0; j < W; j++) {
      if (!isOutW.at(j)) {
        continue;
      }
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}
