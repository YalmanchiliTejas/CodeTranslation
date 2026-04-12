#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  vector<string> G(H);
  for (int i = 0; i < H; ++i) cin >> G[i];

  vector<int> RH;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (G[i][j] == '#') {
        RH.emplace_back(i);
        break;
      }
    }
  }

  vector<int> RW;
  for (int i = 0; i < W; ++i) {
    for (auto j : RH) {
      if (G[j][i] == '#') {
        RW.emplace_back(i);
        break;
      }
    }
  }

  for (auto i : RH) {
    for (auto j : RW) {
      cout << G[i][j];
    }
    cout << endl;
  }
  return 0;
}
