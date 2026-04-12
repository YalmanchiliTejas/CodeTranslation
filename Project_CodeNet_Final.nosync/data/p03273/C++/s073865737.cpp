#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int H, W;
  char G[102][102];
  // 出力しない行
  vector<int> v1;
  // 出力しない列
  vector<int> v2;

  cin >> H >> W;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> G[i][j];
    }
    G[i][W] = '\n';
  }

  for (int i = 0; i < H; i++) {
    bool flag = true;
    for (int j = 0; j < W; j++) {
      if (G[i][j] == '#') {
        flag = false;
      }
    }
    if (flag) { v1.push_back(i); }
  }

  for (int i = 0; i < W; i++) {
    bool flag = true;
    for (int j = 0; j < H; j++) {
      if (G[j][i] == '#') {
        flag = false;
      }
    }
    if (flag) { v2.push_back(i); }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j <= W; j++) {
      if (find(v1.begin(), v1.end(), i) != v1.end()) {
        continue;
      }
      if (find(v2.begin(), v2.end(), j) != v2.end()) {
        continue;
      }
      cout << G[i][j];
    }
  }
  return 0;
}
