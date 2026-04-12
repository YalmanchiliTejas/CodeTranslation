#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<vector<char>> table(H, vector<char>(W));
  
  vector<char> clear_h(H, 'o');
  vector<char> clear_w(W, 'o');

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
    }
  }
  
  int counter = 0;
  // 行ごと
  for (int i = 0; i < H; i++) {
    int counter = 0;
    for (int j = 0; j < W; j++) {
      if (table.at(i).at(j) == '.') {
        counter++;
      }
    }
    if (counter == W) {
      clear_h.at(i) = 'x';
    }
  }
  // 列ごと
  for (int j = 0; j < W; j++) {
    int counter = 0;
    for (int i = 0; i < H; i++) {
      if (table.at(i).at(j) == '.') {
        counter++;
      }
    }
    if (counter == H) {
      clear_w.at(j) = 'x';
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (clear_h.at(i) != 'x' && clear_w.at(j) != 'x') {
        cout << table.at(i).at(j);
      }
    }
    if (clear_h.at(i) != 'x') {
      cout << endl;
    }
  }
}