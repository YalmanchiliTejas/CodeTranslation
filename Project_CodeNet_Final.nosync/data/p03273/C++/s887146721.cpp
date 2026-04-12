#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> table(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> table.at(i).at(j);
    }
  }

  vector<int> skipH;
  for (int i = 0; i < H; i++) {
    int cnt = 0;
    for (int j = 0; j < W; j++) {
      if (table.at(i).at(j) == '.') {
        cnt++;
      }
      if (cnt == W) {
        skipH.push_back(i);
      }
    }
  }

  vector<int> skipW;
  for (int j = 0; j < W; j++) {
    int cnt = 0;
    for (int i = 0; i < H; i++) {
      if (table.at(i).at(j) == '.') {
        cnt++;
      }
      if (cnt == H) {
        skipW.push_back(j);
      }
    }
  }

  for (int i = 0; i < H; i++) {
    bool flag = false;
    for (int skip : skipH) {
      if (i == skip) {
        flag = true;
        break;
      }
    }
    
    if (flag == true) {
      continue;
    }
    
    for (int j = 0; j < W; j++) {
      bool flag = false;
      for (int skip : skipW) {
        if (j == skip) {
          flag = true;
          break;
        }
      }

      if (flag == true) {
        continue;
      }

      cout << table.at(i).at(j);
    }
    cout << endl;
  }
}
