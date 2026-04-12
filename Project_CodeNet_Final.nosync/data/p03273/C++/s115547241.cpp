#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  //二次元配列の宣言
  int M = max(H, W);
  vector<vector<char>> data(M, vector<char>(M, '.'));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> data.at(i).at(j);
    }
  }
  //圧縮した回数
  int countH = 0;//行の圧縮
  int countW = 0;//列の圧縮

  vector<char> vec(M, '.');
  
  //行の圧縮
  for(int i = 0; i < H; i++){
    
    if(data.at(i) == vec){
      if(i != H-1){
          for(int k = i; k < M-1; k++){
            data.at(k) = data.at(k+1);
          }
      }
      i--;
      H--;
      countH++;
    }
  }
  
  //列と行の入れ替え
  vector<vector<char>> data2(M, vector<char>(M, '.'));
  data2 = data;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < M; j++){
      data2.at(i).at(j) = data.at(j).at(i);
    }
  }
  
  //列の圧縮
  for(int i = 0; i < W; i++){
    if(data2.at(i) == vec){
      if(i != W-1){
          for(int k = i; k < M-1; k++){
            data2.at(k) = data2.at(k+1);
          }
      }
      i--;
      W--;
      countW++;
    }
  }
  
  //出力
  for(int i = 0; i < H ; i++){
    for(int j = 0; j < W ; j++){
      cout << data2.at(j).at(i);
    }
    cout << endl;
  }
}







