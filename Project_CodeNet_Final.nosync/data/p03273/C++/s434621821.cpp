#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  
  for (int i = 0; i < H; i++) {
    cin >> S.at(i);
  }
  
  // '#'のある行と列をカウントする
  // xは縦方向のカウンタ，yは横方向のカウンタ
  // 0なら白，1なら黒
  string x = "", y = "";
  for (int i = 0; i < H; i++)
    x += '0';
  for (int i = 0; i < W; i++)
    y += '0';
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S.at(i).at(j) == '#') {
        x.at(i) = '1';
        y.at(j) = '1';
      }      
    }
  }
  
  for (int i = 0; i < H; i++) {
    // xが'0'の行は飛ばす
    if (x.at(i) == '0')
      continue;
    // yが'1'の時のみSを出力する
    else {
      for (int j = 0; j < W; j++) {
        if (y.at(j) == '1')
          cout << S.at(i).at(j);     
      }
      cout << endl;
    }
  }

}