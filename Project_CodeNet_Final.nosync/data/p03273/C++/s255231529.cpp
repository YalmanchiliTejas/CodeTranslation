#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> board(H, vector<char>(W));
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> board.at(i).at(j);
    }
  }
  
  vector<int> remove_yoko(0);
  
  for (int i = 0; i < H; i++){
    int num = 0;
    for (int j = 0; j < W; j++){
      if (board.at(i).at(j) == '.'){
        num++;
      }
      
      if (num == W){
        remove_yoko.push_back(i);
      }
      
    }
  }
  
  vector<int> remove_tate(0);
  
  for (int i = 0; i < W; i++){
    int num = 0;
    for (int j = 0; j < H; j++){
      if (board.at(j).at(i) == '.'){
        num++;
      }
      
      if (num == H){
        remove_tate.push_back(i);
      }
      
    }
  }
  
  for (int i = 0; i < H; i++){
    if (find(remove_yoko.begin(), remove_yoko.end(), i) != remove_yoko.end()){
      continue;
    }
    for (int j = 0; j < W; j++){
      if (find(remove_tate.begin(), remove_tate.end(), j) != remove_tate.end()){
        if (j == W - 1){
          cout << endl;
        }
        continue;
      }
      
      cout << board.at(i).at(j);
      
      if (j == W - 1){
        cout << endl;
      }
    }
  }
  
}