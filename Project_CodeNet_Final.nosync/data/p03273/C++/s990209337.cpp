#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> a(H, vector<char>(W));
  vector<bool> rowEnable(H, false);
  vector<bool> columnEnable(W, false);
  
  // 入力
  for( int i=0; i<H; i++ ){
    for( int j=0; j<W; j++ ){
      cin >> a.at(i).at(j);
      if( a.at(i).at(j) == '#' ){
        rowEnable.at(i) = true;
        columnEnable.at(j) = true;
      }
    }
  }
  
  // 出力
  for( int i=0; i<H; i++ ){
    if( rowEnable.at(i) ){
      for( int j=0; j<W; j++ ){
        if( columnEnable.at(j) ){
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }
}
