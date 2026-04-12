#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vec(H, vector<char>(W));
  for(int i=0; i<H; ++i){
    for(int j=0; j<W; ++j){
      cin >> vec.at(i).at(j);
    }
  }
  
  vector<bool> yoko(H,false);
  for(int i=0; i<H; ++i){
    for(int j=0; j<W; ++j){
      if(vec.at(i).at(j)=='#') yoko.at(i)=true;
    }
  }
  vector<bool> tate(W,false);
  for(int j=0; j<W; ++j){
    for(int i=0; i<H; ++i){
      if(vec.at(i).at(j)=='#') tate.at(j)=true;
    }
  }
  
  for(int i=0; i<H; ++i){
    if(yoko.at(i)==false) continue;
    for(int j=0; j<W; ++j){
      if(tate.at(j)==false) continue;
      cout << vec.at(i).at(j);
    }
    cout << endl;
  }
}