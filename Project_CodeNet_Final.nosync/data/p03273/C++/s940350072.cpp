#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++)
      cin >> grid.at(i).at(j);
  }
  vector<bool> gyo(H,false);
  vector<bool> retu(W, false);
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if (grid.at(i).at(j) == '#'){
        gyo.at(i) = true;
        retu.at(j) = true;
      }
    }
  }
  for(int i=0; i<H; i++){
    if(gyo.at(i)){
      for(int j=0; j<W; j++){
        if(retu.at(j))
          cout << grid.at(i).at(j);
      }
      cout << endl;
    }
  }
}