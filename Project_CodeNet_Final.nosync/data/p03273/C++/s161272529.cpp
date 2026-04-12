#include <bits/stdc++.h>
using namespace std;

int main() {
  int H , W;
  cin >> H >> W;
  
  vector<vector<char>> grid(H, vector<char>(W));
  
  for(int i = 0; i < H; i++) {
    for(int k = 0; k < W; k++) {
      cin >> grid.at(i).at(k);
    }
  }
  
  for(int i = 0; i < H; i++) {
    for(int k = 0; k < W; k++) {
      if(grid.at(i).at(k) == '#') {
        break;
      }
      if(k == W - 1) {
        for(int x = 0; x < W; x++){
          grid.at(i).at(x) = 'x'; //横削除マーク
        }
      }
    }
  }
  for(int k = 0; k < W; k++) {
    for(int i = 0; i < H; i++) {
      if(grid.at(i).at(k) == '#') {
        break;
      }
      if(i == H - 1) {
        for(int x = 0; x < H; x++){
          grid.at(x).at(k) = 'x'; //縦削除マーク
        }
      }
    }
  }
  
  for(int i = 0; i < H; i++) {
    for(int k = 0; k < W; k++) {
      if(grid.at(i).at(k) == 'x') {
        if(k == W - 1) {
          for(int m = 0; m < W ; m++) {
            if(grid.at(i).at(m) == '#'){
              cout << endl;
              break;
            }
          }
        }
        continue;
      }
      else {
        cout << grid.at(i).at(k);
      }
      if(k == W - 1) {
        cout << endl;
      }
    }
  }
}
