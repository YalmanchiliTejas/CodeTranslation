#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> grid(H, vector<char>(W)); 
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> grid.at(i).at(j);
    }
  }
  
  vector<vector<bool>> del(H, vector<bool>(W)); // true のとき表示しない
  for(int i = 0; i < H; i++){
    bool white = true;
    
    for(int j = 0; j < W; j++){
      if(grid.at(i).at(j) == '#'){
        white = false;
      }
    }
    
    if(white){
      for(int j = 0; j < W; j++){
        del.at(i).at(j) = true;
      }
    }
  }
  
  for(int i = 0; i < W; i++){
    bool white = true;
    
    for(int j = 0; j < H; j++){
      if(grid.at(j).at(i) == '#'){
        white = false;
      }
    }
    
    if(white){
      for(int j = 0; j < H; j++){
        del.at(j).at(i) = true;
      }
    }
  }
  
  for(int i = 0; i < H; i++){
    bool black = false;
    
    for(int j = 0; j < W; j++){
      if(del.at(i).at(j) == false){
        cout << grid.at(i).at(j);
        
        black = true;
      }
    }
    
    if(black){
      cout << endl;
    }
  }
  
}