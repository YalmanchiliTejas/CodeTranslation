#include<bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W,'.'));
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> a.at(i).at(j); 
    }
  }

  vector<bool> blankH(H, false), blankW(W, false);
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(a.at(i).at(j) == '#'){
        blankH.at(i) = true;
        blankW.at(j) = true;
      }
    }
  }
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(blankH.at(i) && blankW.at(j)){
        cout << a.at(i).at(j);
      }
    }
    if(blankH.at(i)) cout << endl;
  }
}