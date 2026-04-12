#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> vec(H,vector<char>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W;j++){
      cin >> vec.at(i).at(j);
    }
  }
  //行の調査
  vector<int> hVec(H);
  for(int i = 0; i < H; i++){
    int c = 0;
    for(int j = 0; j < W;j++){
      if(vec.at(i).at(j) == '.'){
        c++;
      } 
    }
    if(c == W){
      hVec.at(i) = 1;
    }
  }
  //列の調査
  vector<int> wVec(W);
  for(int i = 0; i < W; i++){
    int c = 0;
    for(int j = 0; j < H;j++){
      if(vec.at(j).at(i) == '.'){
        c++;
      } 
    }
    if(c == H){
      wVec.at(i) = 1;
    }
  }
  for(int i = 0; i < H; i++){
    if(hVec.at(i) == 1){
      continue;
    }
    for(int j = 0; j < W;j++){
      if(wVec.at(j) == 1){
        continue;
      }
      cout << vec.at(i).at(j);
    }
    cout << endl;
  }
  
}