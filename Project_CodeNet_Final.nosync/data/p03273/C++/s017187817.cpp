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
  for (int i = 0; i < H; i++) {
    bool flag = true;
    for (int j = 0; j < W; j++) {
      if (table.at(i).at(j) == '#') {
        flag = false;
        break;
      }
    }
    if (flag) {
      H--;
      for (int k = i; k < H; k++) {
        for (int l = 0; l < W; l++) {
          table.at(k).at(l) = table.at(k+1).at(l);
        }
      }
      i--;
    }
  } 
  for (int j = 0; j < W; j++) {
    bool flag = true;
    for (int i = 0; i < H; i++) {
      if (table.at(i).at(j) == '#') {
        flag = false;
        break;
      }
    }
    if (flag) {
      W--;
      for (int k = j; k < W; k++) {
        for (int l = 0; l < H; l++) {
          table.at(l).at(k) = table.at(l).at(k+1);
        }
      }
      j--;
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << table.at(i).at(j);
      if (j == W - 1) {
        cout <<endl;
      }
    }
  }
}