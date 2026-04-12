#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> R(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++){
      cin >> R.at(i).at(j);
    } 
  }
  
  vector<int> Hcomp(H), Wcomp(W);
  
  // compress H
    
  for (int i = 0; i < H; i++){
  	bool flag = true;   
    for (int j = 0; j < W; j++){
      if(R.at(i).at(j) == '#'){
        flag = false;
      }
    }
    if (flag){
      Hcomp.at(i) = 1;
    }
  }

  // compress W
    
  for (int i = 0; i < W; i++){
  	bool flag = true;   
    for (int j = 0; j < H; j++){
      if(R.at(j).at(i) == '#'){
        flag = false;
      }
    }
    if (flag){
      Wcomp.at(i) = 1;
    }
  }
  
  // output
  
  for (int i = 0; i < H; i++){
    if(Hcomp.at(i) == 0){
      for (int j = 0; j < W; j++){
      	if(Wcomp.at(j) == 0){
      	  cout << R.at(i).at(j);   
        }
      }
      cout << endl;
    }
  }
}

