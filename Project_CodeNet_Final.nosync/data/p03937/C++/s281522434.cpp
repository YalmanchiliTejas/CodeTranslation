#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, X = 0;
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char A;
      cin >> A;
      if (A == '#') X++;
    }
  }
  if (X == H + W - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}