#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  // H × W 要素の配列を宣言
  vector<vector<char>> data(H, vector<char>(W));

  vector<int> data_FragH(H);
  vector<int> data_FragW(W);
  // 入力
  for (int j = 0; j < H; j++) {
      for (int k = 0; k < W; k++) {
        cin >> data.at(j).at(k);
      }
   }
  
  int count;
  for( int i = 0; i < H; i++){
    count = 0;
    for ( int j = 0; j < W; j++){
      if ( data.at(i).at(j) == '.'){
        count++;
      }
    }
    if(count == W){
      data_FragH.at(i)=1;
    }
  }
  for( int i = 0; i < W; i++){
    count = 0;
    for ( int j = 0; j < H; j++){
      if ( data.at(j).at(i) == '.'){
        count++;
      }
    }
    if(count == H){
      data_FragW.at(i)=1;
    }
  }
  
  //出力
  for (int i = 0; i < H; i++) {
    if (data_FragH.at(i)==0){
      for (int j = 0; j < W; j++) {
        if (data_FragW.at(j)==0){
        	cout << data.at(i).at(j);
        }
      }
      cout << endl;
    }
    
   }
}