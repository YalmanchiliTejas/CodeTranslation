#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<int> X(H), Y(W);
  vector<vector<char>> A(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
      if (A.at(i).at(j) == '#') X.at(i) = 1, Y.at(j) = 1;
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (X.at(i) && Y.at(j)) cout << A.at(i).at(j);
    }
    if (X.at(i)) cout << "\n";
  }
}