#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> table(H,vector<char>(W));
  vector<int> height(H,0), width(W,0); // 行・列に'.'がいくつ含まれるか
  int elih=0,eliw=0; // 消す行・列数
    
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
  	  cin >> table.at(i).at(j);
      if(table.at(i).at(j) == '.'){
        height.at(i)++;
        width.at(j)++;
      }
      if(j == W - 1 && height.at(i)==W){
        elih ++;
      }
      if(i == H - 1 && width.at(j)==H){
        eliw ++;
      }
    }
  }  
  
  H -= elih;
  W -= eliw;
  
  vector<vector<char>> ans(H, vector<char>(W));
  int ri=0, rj=0; //修正後の対応行列番号
  
  for (int i = 0; i < H + elih; i++) {
    if (height.at(i) == W + eliw){
      continue;
    }
    for (int j = 0; j < W + eliw; j++) {
      if (width.at(j) == H + elih){
        continue;
      }
      ans.at(ri).at(rj) = table.at(i).at(j);
      rj ++;
    }
    rj = 0;
    ri ++;
  }    
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
  	  cout << ans.at(i).at(j);
      if (j == W - 1) {
        cout << endl; // 末尾なら改行
      }
    }
  }
}