#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<string>vec(H);
  for (int i = 0; i < H; i++) {
    cin >> vec.at(i);
  }
  
  vector<vector<char>> game(H,vector<char> (W) );
  
  for (int i=0; i < H; i++){
  for (int j=0; j < W; j++){
  game.at(i).at(j) = vec.at(i)[j];
  }
  }
  
  vector<int>gyou(0);
  vector<int>retsu(0);
  
  for (int i=0; i < H; i++){
    bool clear = true;
  for (int j=0; j < W; j++){
  if (game.at(i).at(j) == '#'){
  clear = false;
    break;
  }  
  }
    if(clear){
    continue;
    }
    
    gyou.push_back(i);
  }
  
  for (int j=0; j < W; j++){
    bool clear = true;
  for (int i=0; i < H; i++){
  if (game.at(i).at(j) == '#'){
  clear = false;
    break;
  }  
  }
    if(clear){
    continue;
    }
    
    retsu.push_back(j);
  }
  
  int m = gyou.size();
  int n = retsu.size();
  
  for (int i = 0; i < m; i++){
  for (int j = 0; j < n; j++){
  cout << game.at( gyou.at(i) ).at( retsu.at(j) );
  }
    cout << endl;
  }
  
}