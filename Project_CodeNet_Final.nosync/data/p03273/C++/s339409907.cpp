#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> vv(H, vector<char> (W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j ++) {
      char c;
      cin >> c;
      vv.at(i).at(j) = c;
    }
  }
  vector<int> vh, vw;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (vv.at(i).at(j) == '#') {
        break;
      }
      if (j == W-1) {
        vh.push_back(i);
      }
    }
  }
  vh.push_back(-1);
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (vv.at(j).at(i) == '#') {
        break;
      }
      if (j == H-1) {
        vw.push_back(i);
      }
    }
  }
  vw.push_back(-1);
  int h=0, w=0;
  for (int i = 0; i < H; i++) {
    if (i == vh.at(h)) {
      h++;
      continue;
    }
    for (int j = 0; j < W;j++) {
      if (j == vw.at(w)) {
        w++;
        continue;
      }
      cout << vv.at(i).at(j);
    }
    w=0;
    cout << endl;
  }
}
  