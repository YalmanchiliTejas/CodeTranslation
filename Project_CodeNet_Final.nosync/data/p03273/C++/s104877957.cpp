#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W) );
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> a.at(i).at(j);
    }
  }
  
  vector<bool> xh(H,false), xw(W,false);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(a.at(i).at(j) == '#') xh.at(i) = true;
    }
  }
  for(int i=0; i<W; i++){
    for(int j=0; j<H; j++){
      if(a.at(j).at(i) == '#') xw.at(i) = true;
    }
  }
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(xh.at(i) && xw.at(j)) cout << a.at(i).at(j);
    }
    if(xh.at(i))cout << endl;
  }  
  
}