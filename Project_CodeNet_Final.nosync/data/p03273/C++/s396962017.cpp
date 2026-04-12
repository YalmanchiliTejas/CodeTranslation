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
  
  vector<int> X(H), Y(W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A.at(i).at(j) == '#') X.at(i)++;
    }
  }
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (A.at(i).at(j) == '#') Y.at(j)++;
    }
  }
  
  for (int i = 0; i < H; i++) {
    if (X.at(i) != 0) {
      for (int j = 0; j < W; j++) {
        if (Y.at(j) != 0) cout << A.at(i).at(j);
      }
      cout << endl;
    }
  }
}