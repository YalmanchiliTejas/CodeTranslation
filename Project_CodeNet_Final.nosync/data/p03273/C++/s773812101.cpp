#include<bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> vec(h,vector<char>(w));
  vector<vector<int>> tor(h,vector<int>(w));
  vector<bool> judge(h);
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> vec.at(i).at(j);
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      for(int k = 0; k < h; k++){
        if(vec.at(k).at(j) == '#'){
          tor.at(i).at(j) += 1;
          break;
        }
      }
      for(int k = 0; k < w; k++){
        if(vec.at(i).at(k) == '#'){
          tor.at(i).at(j) += 1;
          break;
        }
      }
    }
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(tor.at(i).at(j) == 2){
        judge.at(i) = false;
        break;
      }
      else if(j == w - 1 && tor.at(i).at(j) != 2){
        judge.at(i) = true;
      }
    }
  }
  for(int i = 0; i < h; i++){
    if(judge.at(i)){
      continue;
    }
    for(int j = 0; j < w; j++){
      if(tor.at(i).at(j) == 2){
        cout << vec.at(i).at(j);
      }
    }
    cout << endl;
  }
}