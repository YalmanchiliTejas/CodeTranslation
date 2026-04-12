#include<bits/stdc++.h>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  //横の空行削除
  for(int i = 0; i < H; i++) {
    bool judge = true;
    for(int j = 0; j < W; j++) {
      if(data.at(i).at(j) == '#') {
        judge = false;
        break;
      }
      
    }
    if(judge) {
      for(int k = 0; k < W; k++) {
        data.at(i).at(k) = '0';
      }
    }
    
  }
  //縦の空列削除
  for(int i = 0; i < W; i++) {
    bool judge = true;
    for(int j = 0; j < H; j++) {
      if(data.at(j).at(i) == '#') {
        judge = false;
        break;
      }
      
    }
    if(judge) {
      for(int k = 0; k < H; k++ ) {
        data.at(k).at(i) = '0';
      }
    }
    
  }
  for(int i = 0; i < H; i++) {
    bool x = false;
    for(int j = 0; j < W; j++) {
      if(data.at(i).at(j) != '0') {
        cout << data.at(i).at(j);
        x = true;
      }
     
    }
    if(x) {
      cout << endl;
    }
    
  }
}