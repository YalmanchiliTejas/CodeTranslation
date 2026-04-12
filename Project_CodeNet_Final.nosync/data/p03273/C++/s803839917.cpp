#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> data (H, vector<char>(W));
  for(int i = 0; i < H; i++){
    string A;
    cin >> A;
    for(int j = 0; j < W; j++){
      data.at(i).at(j) = A.at(j);
    }
  }
  //横--------------
  for(int i = 0; i < H; i++){
    int count = 0;
    
    for(int j = 0; j < W; j++){
      if(data.at(i).at(j) != '#'){
        count++;
      }
    }
    
    if(count == W){
      for(int k = 0; k < W; k++){
        data.at(i).at(k) = '-';
      }
    } 
  }
  //縦--------------
  for(int i = 0; i < W; i++){
    int count = 0;
    
    for(int j = 0; j < H; j++){
      if(data.at(j).at(i) != '#'){
        count++;
      }
    }
    
    if(count == H){
      for(int k = 0; k < H; k++){
        data.at(k).at(i) = '-';
      }
    } 
  }
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(data.at(i).at(j) != '-'){
        cout << data.at(i).at(j);
      }
    }
    cout << endl;
  }
  
}
