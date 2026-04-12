#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> a(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }
  
  for (int i = 0; i < H; i++) {
    bool empty = true;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        empty = false;
        break;
      }
    }
    if (empty) a.at(i).clear();
  }
  
  for (int j = 0; j < W; j++) {
    bool empty = true;
    for (int i = 0; i < H; i++) {
      if (a.at(i).empty()) continue;
      if (a.at(i).at(j) == '#') {
        empty = false;
        break;
      }
    }
    if (empty) {
      for (int i = 0; i < H; i++) {
        if (a.at(i).empty()) continue;
        a.at(i).at(j) = '\0';
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (a.at(i).empty()) continue;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '\0') continue;
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}
