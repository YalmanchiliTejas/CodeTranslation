#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int H, W, i, j;
  cin >> H >> W;
  
  vector<vector<char>> table(H , vector<char>(W));
  for(i = 0; i < H; i++)
    for(j = 0; j < W; j++)
      cin >> table.at(i).at(j);
  
  vector<bool> row_h(H, false);
  vector<bool> row_w(W, false);
  
  for(i = 0; i < H; i++)
    for(j = 0; j < W; j++){
      	if(table.at(i).at(j) == '#'){
          row_h.at(i) = true;
          break;
        }
    }
   for(i = 0; i < W; i++)
    for(j = 0; j < H; j++){
      	if(table.at(j).at(i) == '#'){
          row_w.at(i) = true;
          break;
        }
    }
  for(i = 0; i < H; i++){
    int flag = 0;
    for(j = 0; j < W; j++){
      if(row_h.at(i) == true && row_w.at(j) == true){
        cout << table.at(i).at(j);
        flag = 1;
      }
    }
    if(flag == 1)
      cout << endl;
  }
}
