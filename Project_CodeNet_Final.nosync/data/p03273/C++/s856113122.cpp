#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> map(H, vector<char>(W));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> map.at(i).at(j);
     }
  }
  
  vector<bool> row(H, false);
  vector<bool> col(W, false);
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if(map.at(i).at(j) == '#'){
        row.at(i) = true;
        col.at(j) = true;
      }//if
    } //for j
  }// for i
  
  for( int i= 0; i < H; i++){
    if(row.at(i)){
      for(int j = 0; j < W; j++){
        if(col.at(j)){
          cout << map.at(i).at(j);
          } //if j
      }// for j
      cout << endl;
     }//if i
  } //for i
}//main