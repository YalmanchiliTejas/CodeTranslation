#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> p(H,vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W ;j++){
      cin >> p.at(i).at(j);
    }
  }
  
  for(int i = 0; i < H; i++){
    bool isspace = true;
    for(int j = 0; j < W ;j++){
      if(p.at(i).at(j) == '#'){
        isspace = false;
        break;
      }
    }    
    if(isspace){
      for(int k = i; k < H-1; k++){
        for(int l = 0; l < W ;l++){
          p.at(k).at(l) = p.at(k+1).at(l);
        }  
      }
      H--;
      i--;
    }
  }
  
  for(int j = 0; j < W; j++){
    bool isspace = true;
    for(int i = 0; i < H ;i++){
      if(p.at(i).at(j) == '#'){
        isspace = false;
        break;
      }
    }    
    if(isspace){
      for(int k = j; k < W-1; k++){
        for(int l = 0; l < H ;l++){
          p.at(l).at(k) = p.at(l).at(k+1);
        }  
      }
      W--;
      j--;
    }
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W ;j++){
      cout << p.at(i).at(j);
      if(j == W-1){
        cout << endl;
      }
    }
  }
}