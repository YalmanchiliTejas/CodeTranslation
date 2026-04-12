#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  
  for (int i = 0; i < H; i++){
    bool flag = true;
    
    for (int j = 0; j < W; j++) {
      if (A.at(i).at(j) == '#') {
        flag = false;
      }
    }
    
    if (flag) {
      for (int j = 0; j < W; j++) {
        A.at(i).at(j) = 'a';
      }
    }
  }
  
  for (int i = 0; i < W; i++){
    bool flag = true;
    
    for (int j = 0; j < H; j++) {
      if (A.at(j).at(i) == '#') {
        flag = false;
      }
    }
    
    if (flag) {
      for (int j = 0; j < H; j++) {
        A.at(j).at(i) = 'a';
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    bool flag = false;
    
    for (int j = 0; j < W; j++) {
      if (A.at(i).at(j) != 'a') {
        cout << A.at(i).at(j);
        flag = true;
      }
    }
    
    if (flag) {
      cout << endl;
    }
  }
}