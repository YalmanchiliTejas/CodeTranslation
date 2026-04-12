#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
        cin >> data.at(i).at(j);
    }
  }
  vector<bool> rflg(H,0);
  vector<bool> cflg(W,0);
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
        if(data.at(i).at(j) == '#'){
            rflg.at(i) = 1;
            cflg.at(j) = 1;
        }
    }
  }

  for (int i = 0; i < H; i++) {
    if(rflg.at(i) == 1){
        for (int j = 0; j < W; j++) {
            if(cflg.at(j) == 1){
                cout << data.at(i).at(j);
            }
            if(j == W - 1) {
                cout << endl; // 末尾なら改行
            }
        }
    }
  }
}
