#include <bits/stdc++.h>
using namespace std;


int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  vector<bool> h_check(H);
  vector<bool> w_check(W);
  
  int i, j;
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      cin >> data.at(i).at(j);  
    }
  }
  
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      if(data.at(i).at(j) == '#'){
      h_check.at(i) = true;
      w_check.at(j) = true;  
      } 
    }
  }
  
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      if(h_check.at(i) == true && w_check.at(j) == true){
        cout << data.at(i).at(j);
      }
      if (j == W-1 && h_check.at(i) == true){
        cout << endl;
      }
    }
  }
}
