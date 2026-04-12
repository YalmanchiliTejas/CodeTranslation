#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> grid.at(i).at(j);
    }
  }
  
  // erase empty rows
  for (int i = 0; i < H; i++){
    bool allWhite = true;
    for (int j = 0; j < W; j++){
      if(grid.at(i).at(j) == '#'){
        allWhite = false;
        break;
      }
    }
    if(allWhite){
      grid.erase(grid.begin() + i);
      H--;
      i--;
    }
  }
  
  // erase empty columns
  for (int i = 0; i < W; i++){
    bool allWhite = true;
    for (int j = 0; j < H; j++){
      if(grid.at(j).at(i) == '#'){
        allWhite = false;
        break;
      }
    }
    if(allWhite){
      for (int k = 0; k < H; k++){
        grid.at(k).erase(grid.at(k).begin() + i);
      }
      W--;
      i--;
    }
  }
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cout << grid.at(i).at(j);
    }
    cout << endl;
  }
}