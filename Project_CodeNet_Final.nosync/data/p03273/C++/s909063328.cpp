#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> MAS(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++){
      cin >> MAS.at(i).at(j);
    }
  }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<bool> BY(H), BT(W);
  for(int i = 0; i<H; i++){
    bool x = false;
    for(int j = 0; j < W; j++){
      if(MAS.at(i).at(j) == '#')x = true;
    }
    BY.at(i) = x;
  }
  for(int i = 0; i<W; i++){
    bool x = false;
    for(int j = 0; j < H; j++){
      if(MAS.at(j).at(i) == '#')x = true;
    }
    BT.at(i) = x;
  }
  
  for(int i=0;i<H;i++){
    if(BY.at(i)){
      for(int j=0;j<W;j++){
        if(BT.at(j)){
          cout << MAS.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
