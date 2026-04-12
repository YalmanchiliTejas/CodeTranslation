#include <bits/stdc++.h>
using namespace std;

int H, W;

int main() {
  cin >> H >> W;
  int x = 0;
  for(int i = 0; i < H * W; ++i) {
    char A; cin >> A; x += A == '#';
  }
  cout << (x == H + W - 1 ? "Possible" : "Impossible") << endl;
  return 0;
}
