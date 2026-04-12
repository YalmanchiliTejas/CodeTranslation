#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> table[i][j];
    }
  }
  
  for(int j = 0; j < W; j++){
    for(int i = 0; i < H; i++){
      if(table[i][j] == '#'){
        break;
      }
      else if(i == H - 1){
        for(int k = 0; k < H; k++){
          table[k][j] = '\0';
        }
      }
    }
  }
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(table[i][j] == '#'){
        break;
      }
      else if(j == W - 1){
        for(int k = 0; k < W; k++){
         table[i] = {};
        }
      }
    }
  }
  

  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(table[i].size() == 0)
        break;
      else if(table[i][j] != '\0')
        cout << table[i][j];
    }
    if(table[i].size() != 0)
      cout << endl;
  }
  
  return 0;
  
}