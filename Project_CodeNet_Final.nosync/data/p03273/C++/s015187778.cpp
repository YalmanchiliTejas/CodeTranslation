#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> Map(H, vector<char>(W));
  vector<bool> Row_remain(H), Col_remain(W);
  
  // input
  for(int i=0; i<H; i++) {
    string str;
    cin >> str;
    for(int j=0; j<W; j++){
   	  Map.at(i).at(j)= str.at(j);
    }
  }

  // walk-through
  //// 残る行を調べる
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++){
   	  if( Map.at(i).at(j)=='#' ){
      	Row_remain.at(i)= true;
        break;
      }
    }
  }
  //// 残る列を調べる
  for(int j=0; j<W; j++){
    for(int i=0; i<H; i++) {
   	  if( Map.at(i).at(j)=='#' ){
      	Col_remain.at(j)= true;
        break;
      }
    }
  }
  
  // output
  for(int i=0; i<H; i++) {
    if( Row_remain.at(i) ){
      for(int j=0; j<W; j++){
   	    if( Col_remain.at(j) ){
      	  cout << Map.at(i).at(j);
        }
   	  }
      cout << endl;
    }
  }
}