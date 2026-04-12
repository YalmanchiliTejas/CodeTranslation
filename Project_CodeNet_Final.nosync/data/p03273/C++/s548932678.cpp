#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> map(H,vector<char>(W));
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> map.at(i).at(j);
  	}
  }
  
  char base;
  char same = false;
  for(int i = 0; i < H; i++){
    same = true;
    for(int j = 0; j < W; j++){
      if(map.at(i).at(j) == '#')
        same = false;
    }
    if(same){
      for(int j = 0; j < W; j++){
        map.at(i).at(j) = 'x';
      }
    }
  }



  for(int i = 0; i < W; i++){
    same = true;
    for(int j = 0; j < H; j++){
      if(map.at(j).at(i) == '#')
        same = false;
    }
    if(same){
      for(int j = 0; j < H; j++){
        map.at(j).at(i) = 'x';
      }
    }
  }
  
  bool out;
  for(int i = 0; i < H; i++){
    out = false;
    for(int j = 0; j < W; j++){
      if(map.at(i).at(j) != 'x'){
        cout<< map.at(i).at(j);
        out = true;
      }
  	}
    if(out){
      cout << endl;
    }
  }

  return 0;
}