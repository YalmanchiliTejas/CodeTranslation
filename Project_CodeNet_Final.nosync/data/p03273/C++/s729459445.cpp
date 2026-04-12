#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  
  vector<bool> flag_w(W,false);
  vector<bool> flag_h(H,false);
  vector<vector<char>> grid(H, vector<char>(W));

  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      cin >> grid.at(i).at(j); 
      if ( grid.at(i).at(j) == '#' ){
        flag_h.at(i) = true;
        flag_w.at(j) = true;
      }
    }
  }

  for (int i=0; i<H; i++){
    if(flag_h.at(i) == true){
      for (int j=0; j<W; j++){
        if(flag_w.at(j) == true){
          cout << grid.at(i).at(j);
       }
      }
    cout << endl;
    }
  }

}