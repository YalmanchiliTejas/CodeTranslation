#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++) cin >> a.at(i);
  set<int> Y, X;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (a.at(y).at(x) == '#') Y.insert(y);
    }
  }
  for (int x = 0; x < W; x++) {
    for (int y = 0; y < H; y++) {
      if (a.at(y).at(x) == '#') X.insert(x);
    }
  }
  for (int y : Y) {
    for (int x : X) cout << a.at(y).at(x);
    cout << endl;
  }
}