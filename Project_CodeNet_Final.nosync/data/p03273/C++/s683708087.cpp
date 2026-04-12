#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, A = 0, B;
  cin >> H >> W;
  vector<vector<char>> S(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> S.at(i).at(j);     
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S.at(i).at(j) == '#') {
        break;
      }
      else if (j == W - 1) {
        for (int k = 0; k < W; k++) {
          S.at(i).at(k) = 'a';
        }
      }
    }
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (S.at(j).at(i) == '#') {
        break;
      }
      else if (j == H - 1) {
        for (int k = 0; k < H; k++) {
          S.at(k).at(i) = 'a';
        }
         A += 1;
      }
    }
  }
  B = A;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S.at(i).at(j) == 'a') {
        continue;
      }
      cout << S.at(i).at(j);
      B += 1;
      if (B == W) {
        cout << endl;
        B = A;
      }
    }
  }
}

