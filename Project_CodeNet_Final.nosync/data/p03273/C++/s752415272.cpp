#include <bits/stdc++.h>
using namespace std;

int main(){
  int H , W;
  cin >> H >> W;
  vector<vector<char>> data(H , vector<char>(W));
  
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      cin >> data.at(i).at(j);
    }
  }
  
  for(int i = 0;i < H;i++){ //横一列を確認
    for(int j = 0;j < W;j++){
      if(data.at(i).at(j) == '.'){
        if(j == W - 1){
          for(int k = 0;k < W;k++){
            data.at(i).at(k) = 'x';
          }
        }
        else{
          continue;
        }
      }
      
      if(data.at(i).at(j) == '#'){
        break;
      }
    }
  }
  
  for(int i = 0;i < W;i++){ //縦一列を確認
    for(int j = 0;j < H;j++){
      if(data.at(j).at(i) == '.' || data.at(j).at(i) == 'x'){
        if(j == H - 1){
          for(int k = 0;k < H;k++){
            data.at(k).at(i) = 'x';
          }
        }
        else{
          continue;
        }
      }
      
      if(data.at(j).at(i) == '#'){
        break;
      }
    }
  }
  
  for(int i = 0 ; i < H;i++){
    for(int j = 0;j < W;j++){
      if(data.at(i).at(j) == '#' || data.at(i).at(j) == '.'){
        cout << data.at(i).at(j);
      }
      if(j == W - 1){
        cout << endl;
      }
    }
  }
      
}