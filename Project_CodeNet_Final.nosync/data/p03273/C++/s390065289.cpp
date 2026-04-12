#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> otable(H,vector<char>(W));
  vector<bool> ha(H, false), wa(W, false);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++){
      cin >> otable.at(i).at(j);
        if (otable.at(i).at(j) == '#'){
          ha.at(i) = true;
          wa.at(j) = true;
      }
    }
  }
// # があれば Trueにする。  

  for (int i = 0; i < H ; i++){
    if (!ha.at(i)){
      continue;
    }
    for (int j = 0 ; j < W ; j++){
      if(wa.at(j)){
        cout << otable.at(i).at(j);  
      }
      if (j == W - 1 ) {
        cout << endl; // 末尾なら改行
      }
    }
  }                                                   
}