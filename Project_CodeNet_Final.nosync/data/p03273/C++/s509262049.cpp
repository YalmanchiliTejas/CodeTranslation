#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  // まず行ごとにとりこむ
  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a.at(i);
  }

  // 判定用変数
  vector<int> row(H);
  vector<int> columnn(W);
  char c;
  
  // 行と列の判定　i行目が全部白なら row.at(i)=0　j列目が全部白なら　columnn.at(j)=0
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        row.at(i) = 1;
        columnn.at(j) = 1;
      }
    }
  }
  
  // 出力
  for (int i = 0; i < H; i++) {
    if (row.at(i) == 0) {
      continue;
    }
    for (int j = 0; j < W; j++) {
      if (columnn.at(j) == 0) {
        continue;
      }
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}