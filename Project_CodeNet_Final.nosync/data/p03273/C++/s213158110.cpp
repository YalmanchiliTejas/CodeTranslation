#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  int i,j;
  vector<vector<char>> a(H, vector<char>(W));
  for (i = 0; i < H; i++){
    for (j = 0; j < W; j++){
      cin >> a.at(i).at(j);
    }
  }

  //行のチェック
  vector<bool> h_flag(H, true);
  for (i = 0; i < H; i++){
    for (j = 0; j < W; j++){
      if (a.at(i).at(j) == '#') {
        h_flag.at(i) = false;
        break;
      }
    }
  }

  //列のチェック
  vector<bool> w_flag(W, true);
  for (i = 0; i < W; i++){
    for (j = 0; j < H; j++){
      if (a.at(j).at(i) == '#'){
        w_flag.at(i) = false;
        break;
      }
    }
  }

  //チェックした行と列を除いて出力する
  for (i = 0; i < H; i++){
    for (j = 0; j < W; j++){
      if (!h_flag.at(i) && !w_flag.at(j)){
        cout << a.at(i).at(j);
      }
    }
    if (!h_flag.at(i)) {
      cout << endl;
    }
  }
}