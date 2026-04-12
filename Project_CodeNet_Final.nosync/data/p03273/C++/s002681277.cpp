#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(H, vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> table.at(i).at(j);
    }
  }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(table.at(i).at(j) == '#'){
        break;
      }
      else if(j == W - 1){
        for(int k = 0; k < W; k++){
        table.at(i).at(k) = '~';
        }
      }
    }
  }
  for(int i = 0; i < W; i++){
    for(int j = 0; j < H; j++){
      if(table.at(j).at(i) == '#'){
        break;
      }
      else if(j == H - 1){
        for(int k = 0; k < H; k++){
        table.at(k).at(i) = '~';
        }
      }
    }
  }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(table.at(i).at(j) == '~' && j == W - 1){
        cout << endl;
      }
      else if(table.at(i).at(j) == '~'){
        continue;
      }
      else if(j == W - 1){
        cout << table.at(i).at(j) << endl;
      }
      else{
        cout << table.at(i).at(j);
      }
    }
  }
}