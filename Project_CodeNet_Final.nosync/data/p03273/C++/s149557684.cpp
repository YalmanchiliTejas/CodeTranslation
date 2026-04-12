#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int H, W;
  cin >> H >> W; 
  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
  cin >> data.at(i).at(j);
    }
  }
  
  vector<int> width(W,0);
  vector<int> high(H,0);
  
  
  int Hsyorisuu =0;
  //横の行の検査
  for (int i = 0; i < H; i++) {
    int count=0;
    for (int j = 0; j < W; j++) {
      if(data.at(i).at(j) == '.'){count++;}
    }
    if (count == W){ 
      high.at(i) = 1;
      Hsyorisuu++;
    }
  }
  
  //行の消去
  int syorisuu=0;
  int tobasitaNo=0;
  vector<vector<char>> gyousyoridata(H-Hsyorisuu, vector<char>(W));
   for (int i = 0; i < H; i++) {
     if(high.at(i) == 1 ){ 
       tobasitaNo++;
       continue; }
    for (int j = 0; j < W; j++) {
  gyousyoridata.at(i-tobasitaNo).at(j) = data.at(i).at(j);
    }
  }
  
  int Wsyorisuu =0;
 //縦の行の検査
  for (int i = 0; i < W; i++) {
    int count=0;
    for (int j = 0; j < H-Hsyorisuu; j++) {
      if(gyousyoridata.at(j).at(i) == '.'){count++;}
    }
    if (count == H-Hsyorisuu){ 
      width.at(i) = 1;
      Wsyorisuu++;
    }
  }   
  
  //縦の行の消去
  syorisuu=0;
  tobasitaNo=0;
  vector<vector<char>> gyouretsusyoridata(H-Hsyorisuu, vector<char>(W-Wsyorisuu));
   for (int i = 0; i < W; i++) {
     if(width.at(i) == 1 ){ 
       tobasitaNo++;
       continue; }
    for (int j = 0; j < H-Hsyorisuu; j++) {
  gyouretsusyoridata.at(j).at(i-tobasitaNo) = gyousyoridata.at(j).at(i);
    }
  }
  
  for (int i = 0; i < H-Hsyorisuu; i++) {
    for (int j = 0; j < W-Wsyorisuu; j++) {
    cout << gyouretsusyoridata.at(i).at(j);
  if (j == W-Wsyorisuu-1) {
    cout << endl; // 末尾なら改行
  }
}
}
//*/
}