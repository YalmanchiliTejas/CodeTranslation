#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<int> h(H,0), w(W,0);
  vector<vector<char>> table(H, vector<char>(W));
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> table.at(i).at(j);
    }
  }
  for(int i = 0; i < H; i++ ){
    int flag = 0;
    for(int j = 0; j < W; j++ ){
      if(table.at(i).at(j) == '#'){
        flag = 1;
        break;
      }
    }
    if(flag == 1){
      h.at(i) = 1;
    }
  }
  for(int i = 0; i < W; i++ ){
    int flag = 0;
    for(int j = 0; j < H; j++ ){
      if(table.at(j).at(i) == '#'){
        flag = 1;
        break;
      }
    }
    if(flag == 1){
      w.at(i) = 1;
    }
  }
  
  for(int i = 0; i < H; i++){
    if(h.at(i) == 0){
      continue;
    }
    for(int j = 0; j < W ; j++){
      if(w.at(j) == 0){
        if(j == W-1){
          cout << endl;
        }
        continue;
      }else{
        cout << table.at(i).at(j);
        if(j == W-1){
          cout << endl;
        }
      }
    }
  }
}