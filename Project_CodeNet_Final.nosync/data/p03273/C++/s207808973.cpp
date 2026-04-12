#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  vector<bool> h(H), w(W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
      if (A.at(i).at(j) == '#') h.at(i) = w.at(j) = true;
    }
  }
  for (int i = 0; i < H; i++) {
    if (!h.at(i)) continue;
    for (int j = 0; j < W; j++) {
      if (!w.at(j)) continue;
      cout << A.at(i).at(j);
    }
    cout << "\n";
  }
}