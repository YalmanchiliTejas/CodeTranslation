#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int H, W; cin >> H >> W;
  vector<string> ss(H);
  for (int i = 0; i < H; ++i) cin >> ss[i];
  vector<bool> br(H, true), bc(W, true);

  for (int r = 0; r < H; ++r) {
    for (int c = 0; c < W; ++c) {
      if (ss[r][c] == '#') {
        br[r] = false, bc[c] = false;
      }
    }
  }

  for (int r = 0; r < H; ++r) {
    if (br[r]) continue;
    for (int c = 0; c < W; ++c) {
      if (bc[c]) continue;
      cout << ss[r][c];
    }
    cout << endl;
  }
}
