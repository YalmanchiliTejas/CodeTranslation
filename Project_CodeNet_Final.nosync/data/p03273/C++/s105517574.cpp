#include<bits/stdc++.h>
using namespace std;

int main(){
  int W,H;
  cin >> H >> W;
  vector<vector<char>> Board(H,vector<char>(W));
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      cin >> Board.at(i).at(j);
    }
  }
  bool flag;
  for(int i = 0; i < H; ++i){
    flag = true;
    for(int j = 0; j < W; ++j){
      flag = (flag && (Board.at(i).at(j)=='.'));
    }
    if(flag){
      //cout << "H" << i << endl; //for debug
      for(int j = 0; j < W; ++j){
        Board.at(i).at(j) = 'e';
      }
    }
  }
  for(int i = 0; i < W; ++i){
    flag = true;
    for(int j = 0; j < H; ++j){
      flag = (flag && ( (Board.at(j).at(i) == '.') || (Board.at(j).at(i) == 'e') ) );
    }
    if(flag){
      //cout << "W" << i << endl; //for debug
      for(int j = 0; j < H; ++j){
        Board.at(j).at(i) = 'e';
      }
    }
  }
  
  bool end = true;
  for(int i = 0; i < H; ++i){
    end = false;
    for(int j = 0; j < W; ++j){
      if(Board.at(i).at(j) != 'e') {
        cout << Board.at(i).at(j);
        end = true;
      }
    }
    if(end) cout << endl;
  }
}