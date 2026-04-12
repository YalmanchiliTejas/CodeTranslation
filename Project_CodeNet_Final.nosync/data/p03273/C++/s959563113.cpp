#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<int> R(H, 0), L(W, 0);
  vector<vector<char>> A(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A.at(i).at(j) == '#') {
        R.at(i) = 1;
        L.at(j) = 1;
      }
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (R.at(i) == 1 && L.at(j) == 1) {
        cout << A.at(i).at(j);
      }  
      if (j == W - 1 && R.at(i) == 1) {
        cout << endl;
      }
    }
  }
}
