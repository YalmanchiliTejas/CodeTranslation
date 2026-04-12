#include <bits/stdc++.h>
using namespace std;

int H, W;

int allblank(vector<vector<char>> table,int i, int j);

int main() {
  
  cin >> H >> W;
  
  vector<vector<char>> table(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
    }
  }
  
  int count = 0;
  for (int i = 0; i < H; i++) {
    count = 0;
    for (int j = 0; j < W; j++) {
      if (allblank(table, i, j) != 1) {
        cout << table.at(i).at(j);
        count ++;
      }
      if (j == W - 1 && count != 0) cout << endl;
      
    }
  }
}

int allblank(vector<vector<char>> table,int i, int j) {
  int countW = 0, countH = 0;
  
  for (int h = 0; h < H; h++) {
    if (table.at(h).at(j) != '.') {
      countH++;
      break;
    }
  }
  
  for (int w = 0; w < W; w++) {
    if (table.at(i).at(w) != '.') {
      countW++;
      break;
    }
  }
  
  if (countH * countW > 0) return 0;
  return 1;
}