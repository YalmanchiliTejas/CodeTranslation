#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> hyo(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> hyo.at(i).at(j);
    }
  }
  int count = 0;
  for (int i = 0; i < W; i++) {
    bool tate_check = true;
    for (int j = 0; j < H; j++) {
      if (hyo.at(j).at(i - count) != '.') {
         tate_check = false;
        break;
      }
    }
    if (tate_check == true){
      for(int k = 0; k < H; k++){
        for (int l = i - count; l < W - 1;l++){
          hyo.at(k).at(l) = hyo.at(k).at(l + 1);
        }
      }
      count++;
    }
  }
  for (int i = 0; i < H; i++) {
    bool yoko_check = false;
    for (int j = 0; j < W; j++) {
      if (hyo.at(i).at(j) != '.') {
         yoko_check = true;
         break;
      }
    }
  if (yoko_check == true){
    for (int j = 0; j < W - count; j++){
      cout << hyo.at(i).at(j);
    }
    cout << endl;
  }
  }
}