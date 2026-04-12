#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W));
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }
  
  vector<bool> gyo(H, false);
  vector<bool> retsu(W, false);

  //行のマーク
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(a.at(i).at(j) == '#') {
        gyo.at(i) = true;
        break;
      }
    }
  }
  //列のマーク
  for(int i = 0; i < W; i++) {
    for(int j = 0; j < H; j++) {
      if(a.at(j).at(i) == '#') {
        retsu.at(i) = true;
        break;
      }
    }
  }
  
  //出力
  for(int i = 0; i < H; i++) {
    if(gyo.at(i)) {
      for(int j = 0; j < W; j++) {
        if(retsu.at(j)) {
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    } else {
      continue;
    }
  }

  return 0;
}