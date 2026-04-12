#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> bmMap(H, vector<char>(W));

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> bmMap.at(i).at(j);
    }
  }

  vector<int> skipH(H);
  vector<int> skipW(W);

  // skipHを求める
  for (int i = 0; i < H; ++i) {
    bool isSkip = true;
    for (int j = 0; j < W; ++j) {
      if (bmMap.at(i).at(j) == '#') {
        isSkip = false;
        break;
      }
    }
    if (isSkip) {
      skipH.at(i) = 1;
    }
  }

  for (int i = 0; i < W; ++i) {
    bool isSkip = true;
    for (int j = 0; j < H; ++j) {
      if (bmMap.at(j).at(i) == '#') {
        isSkip = false;
        break;
      }
    }
    if (isSkip) {
      skipW.at(i) = 1;
    }
  }

  // 表示
  for (int i = 0; i < H; ++i) {
    if (skipH.at(i)) {
      continue;
    }
    for (int j = 0; j < W; ++j) {
      if (skipW.at(j)) {
        continue;
      }
      cout << bmMap.at(i).at(j);
    }
    cout << endl;
  }
}