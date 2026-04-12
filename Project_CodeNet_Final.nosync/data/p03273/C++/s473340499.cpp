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
  vector<bool> B1(H, true);
  for (int i = 0; i < H; i++) {
    bool b = 1;
    for (int j = 0; j < W; j++) {
      if (A.at(i).at(j) == '#') b = 0;
    }
    if (b) B1.at(i) = false;
  }
  vector<bool> B2(W, true);
  for (int i = 0; i < W; i++) {
    bool b = 1;
    for (int j = 0; j < H; j++) {
      if (A.at(j).at(i) == '#') b = 0;
    }
    if (b) B2.at(i) = false;
  }
  for (int i = 0; i < H; i++) {
    if (!B1.at(i)) continue;
    for (int j = 0; j < W; j++) {
      if (!B2.at(j)) continue;
      cout << A.at(i).at(j);
    }
    cout << "\n";
  }
}