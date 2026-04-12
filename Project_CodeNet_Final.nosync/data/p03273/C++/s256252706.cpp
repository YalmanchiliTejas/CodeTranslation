#include<bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int k = 0; k < W; k++) cin >> data.at(i).at(k);
  }
  
  for (int i = 0; i < H; i++) {
    bool disc = true;
    for (int k = 0; k < W; k++) {
      if (data.at(i).at(k) == '.') continue;
      disc = false; 
      break;
    }
    if (disc) {
      for (int k = 0; k < W; k++) data.at(i).at(k) = 'o';
    }
  }
  
  for (int k = 0; k < W; k++) {
    bool disc = true;
    for (int i = 0; i < H; i++) {
      if (data.at(i).at(k) == '.' || data.at(i).at(k) == 'o') continue;
      disc = false;
      break;
    }
    if (disc) {
      for (int i = 0; i < H; i++) data.at(i).at(k) = 'o';
    }
  }
  
  for (int i = 0; i < H; i++) {
    bool disc = false;
    for (int k = 0; k < W; k++) {
      if (data.at(i).at(k) != 'o') {cout << data.at(i).at(k); disc = true;}
    }
    if (disc) cout << endl;
  }
}