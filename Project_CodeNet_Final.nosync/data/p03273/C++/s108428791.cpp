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
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) == '#') {
        break;
      }
      else if (j == W - 1) {
        for (int k = 0; k < W; k++) {
          a.at(i).at(k) = '%';
        }
      }
    }
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (a.at(j).at(i) == '#') {
        break;
      }
      else if (j == H - 1) {
        for (int k = 0; k < H; k++) {
          a.at(k).at(i) = '%';
        }
      }
    }
  }
  for (int i = 0; i < H; i++) {
    int A = 0;
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) != '%') {
        cout << a.at(i).at(j);
        A = 1;
      }
    }  
    if (A == 1) {
      cout << endl;
    }
  }
}