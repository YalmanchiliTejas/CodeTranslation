#include <bits/stdc++.h>
using namespace std;
     
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  
  vector<bool> authRow(H,false);
  vector<bool> authCol(W,false);
  for(int CH=0; CH<H; CH++){
    for(int CW=0; CW<W; CW++){
      cin >> a.at(CH).at(CW);
      if(a.at(CH).at(CW)=='#'){
        authRow.at(CH)=true;
        authCol.at(CW)=true;
      }
    }
  }
  
  for(int CH=0; CH<H; CH++){
    if(authRow.at(CH)){
      for(int CW=0; CW<W; CW++){
        if(authCol.at(CW)) cout << a.at(CH).at(CW);
      }
      cout << endl;
    }
  }
  return 0;
}