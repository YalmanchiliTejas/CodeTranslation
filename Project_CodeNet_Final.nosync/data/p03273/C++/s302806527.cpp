#include <bits/stdc++.h>
using namespace std;

 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<bool>> TF(H, vector<bool> (W,true));
  vector<vector<char>> shoki(H, vector<char> (W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char x;
      cin >> x;
      shoki.at(i).at(j) = x;
    }
  }
  for (int i = 0; i < H; i++) {
    bool x = true;
    for (int j = 0; j < W; j++) {
      if (shoki.at(i).at(j) == '#') {
        x = false;
        break;
      }
    }
    if (x) {
      for (int j = 0; j < W; j++) {
        TF.at(i).at(j) = false;
      }
    }
  }
  int count = W;
  for (int j = 0; j < W; j++) {
    bool x = true;
    for (int i = 0; i < H; i++) {
      if (shoki.at(i).at(j) == '#') {
        x = false;
        break;
      }
    }
    if (x) {
      for (int i = 0; i < H; i++) {
        TF.at(i).at(j) = false;
      }
      count -= 1;
    }
  }
  for (int i = 0; i < H; i++) {
    int total = 0;
    for (int j = 0; j < W; j++) {
      if (TF.at(i).at(j)) {
        cout << shoki.at(i).at(j);
        total += 1;
      }
      if (total == count) {
        cout << endl;
        break;
      }
    }
  }
}   