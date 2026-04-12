#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> data.at(i).at(j);
    }
  }
  
  //ドットだけの行があればその行を全部'-'にする
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (data.at(i).at(j) == '#'){
        break;
      }
      else if (j == W - 1){
        for (int k = 0; k < W; k++){
          data.at(i).at(k) = '-';
        }
      }
    }
  }
  
  //ドットだけの列があればその列を全部'1'にする
  for (int j = 0; j < W; j++){
    for (int i = 0; i < H; i++){
      if (data.at(i).at(j) == '#'){
        break;
      }
      else if (i == H - 1){
        for (int k = 0; k < H; k++){
          data.at(k).at(j) = '1';
        }
      }
    }
  }
        
  //0以外のものを出力していく
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (data.at(i).at(j) == '-'){
        break;
      }
      else if (data.at(i).at(j) != '1'){
        cout << data.at(i).at(j);
      }
      if (j == W - 1){
        cout << " " <<endl;
      }
    }
  }
}