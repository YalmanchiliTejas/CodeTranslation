#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  // 読み込み
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid.at(i).at(j);
    }
  }
  
  // 省略する行と列の判定
  vector<bool> row(H, false); // 行に#が含まれるか
  vector<bool> col(W, false); // 列に#が含まれるか
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '#'){
        row.at(i) = true;
        col.at(j) = true;
      }
    }
  }
  
  // 出力
  for (int i = 0; i < H; i++) {
    if (!row.at(i)) continue;
    for (int j = 0; j < W; j++) {
      if (!col.at(j)) continue;
      cout << grid.at(i).at(j);
    }
    cout << endl;
  }
}