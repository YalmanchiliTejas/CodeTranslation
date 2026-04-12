// ABC 107 B- Grid Compression
// 多次元配列

#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  // 入力ます目
  vector<vector<char>> data(H, vector<char> (W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  // 黒いますがあるかどうかboolで判断
  // 列および行をチェック
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == '#') {
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }
  // 出力
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (row.at(i) == true && col.at(j) == true) {
        cout << data.at(i).at(j);
      }
      if (j == W-1 && row.at(i) == true) {
        cout << endl;
      }
    }
  }
}
