#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> mat(H,vector<char>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> mat.at(i).at(j);
    }
  }
  for(int i=0; i<H; i++){
    bool color = 0;
    for(int j=0; j<W;j++){
      if(mat.at(i).at(j) == '#'){
        color = 1;
      }
    }
    if(!color){
      for(int k=i; k<H-1; k++){
        for(int j=0; j<W; j++){
          mat.at(k).at(j) = mat.at(k+1).at(j);
        }
      }
      H--;
      i--;
    }
  }

  for(int j=0; j<W; j++){
    bool color = 0;
    for(int i=0; i<H; i++){
      if(mat.at(i).at(j) == '#'){
        color = 1;
      }
    }
    if(!color){
      for(int k=j; k<W-1; k++){
        for(int i=0; i<H; i++){
          mat.at(i).at(k) = mat.at(i).at(k+1);
        }
      }
      W--;
      j--;
    }
  }
  
  for(int i=0; i<H; i++){
    for(int j=0; j<W-1; j++){
      cout << mat.at(i).at(j);
    }
    cout << mat.at(i).at(W-1) << endl;
  }
}