#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> data(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  for (int i = 0; i < H; i++) {
    int white = 0;
      for (int j = 0; j < W; j++){
      if(data.at(i).at(j) == '.') {white++;}}
    
    if(white == W)    
    {
      for(int j = 0; j < W; j++) {
        data.at(i).at(j) = 'k';}
    }
  

  }
  
   
  
  for (int j = 0; j < W; j++) {
    int white = 0;
      for (int i = 0; i < H; i++){
      if(data.at(i).at(j) != '#') {white++;}}
    
    if(white == H)    
    {
      for(int i = 0; i < H; i++) {
        data.at(i).at(j) = 'k';}
    }
  

  }
  
  
  for (int i = 0; i < H; i++) {
    int white = 0;
    for (int j = 0; j < W; j++) {  
      if(data.at(i).at(j) != 'k') {
      cout << data.at(i).at(j);} else {white++;}
    }
    if(white != W){cout << endl;}
  }
}
  