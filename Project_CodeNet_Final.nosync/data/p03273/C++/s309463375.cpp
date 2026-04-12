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
  
  //横
  for (int i = 0; i < H; i++) {
    int yoko = 0;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '.'|| a.at(i).at(j) == '*') yoko++;
    }
    for (int j = 0; j < W; j++) {
      if (yoko == W) a.at(i).at(j) = '*';
    }
  }
  
  //縦
  for (int i = 0; i < W; i++) {
    int tate = 0;
    for (int j = 0; j < H; j++) {
      if (a.at(j).at(i) == '.' || a.at(j).at(i) == '*') tate++;
    }
    for (int j = 0; j < H; j++) {
      if (tate == H) a.at(j).at(i) = '*';
    }
  }
  
  //出力
  for (int i = 0; i < H; i++) {
    int count = 0;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '*') {
        count++;
        continue;
      }
      cout << a.at(i).at(j);
    }
    if (count != W) cout << endl;
  }
}
