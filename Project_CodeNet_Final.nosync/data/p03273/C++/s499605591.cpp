#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  for(int h = 0; h < H; h++) {
    for(int w = 0; w < W; w++) {
      cin >> table.at(h).at(w);
    }
  }

  vector<bool> hflag(H,true);
  vector<bool> wflag(W,true);

  // 行列チェック
  for(int h = 0; h < (int)table.size(); h++) {
    for(int w = 0; w < (int)table.at(0).size(); w++) {
      if( table.at(h).at(w) == '#') {
        hflag.at(h) = false;
        wflag.at(w) = false;
      }
    }
  }

  // falseのときはスキップして出力
  for(int h = 0; h < (int)table.size(); h++){
    if(hflag.at(h)) continue;
    for(int w = 0; w < (int)table.at(h).size(); w++){
      if(wflag.at(w)) continue;
      cout << table.at(h).at(w);
    }
    cout << endl;
  }

}
