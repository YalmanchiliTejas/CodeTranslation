#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H;
  cin >> W;


   vector<vector<char>> matrix(H, vector<char>(W));

  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> matrix.at(i).at(j);
    }
  }  


  int hcheck = 0;
  vector<bool> hflag(H, false);
  int wcheck = 0;
  vector<bool> wflag(W, false);

  for (int i = 0; i < matrix.size(); i++){
    for (int j=0; j< matrix.at(0).size();j++){
      if(matrix.at(i).at(j) == '#') {
        hflag.at(i) = true;
        wflag.at(j) = true; 
      }
    }
  }
  for (int i = 0; i < matrix.size(); i++){
    for (int j=0; j< matrix.at(0).size();j++){
      if(hflag.at(i) == true  && wflag.at(j) == true ) {
          cout << matrix.at(i).at(j);
      }
      
    }
    if (hflag.at(i) == true) cout << endl;
  }
}
