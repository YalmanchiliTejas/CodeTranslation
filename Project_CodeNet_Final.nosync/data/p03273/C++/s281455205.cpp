#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++){
      cin >> table.at(i).at(j);
    }
  }

  vector<int> H_, W_;

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(table.at(i).at(j) == '#'){
        H_.push_back(i);
        break;
      }
    }
  }
  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(table.at(j).at(i) == '#'){
        W_.push_back(i);
        break;
      }
    }
  } 
  
  for(int i : H_){
    for(int j : W_){
      cout << table.at(i).at(j);
    }
    cout << endl;
  }
}

