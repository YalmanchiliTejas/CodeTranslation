#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w ; cin >> h >> w;
  vector<string> G(h);
  for (auto &s : G) cin >> s;
  vector<int> height, width;
  for (int i=0; i<h; ++i) {
    for (int j=0; j<w; ++j) {
      if (G[i][j] == '#') {
        height.push_back(i);
        break;
      }
    }
  }
  for (int j=0; j<w; ++j) {
    for (int i=0; i<h; ++i) {
      if (G[i][j] == '#') {
        width.push_back(j);
        break;
      }
    }
  }
  for (auto &i : height) {
    for (auto &j : width) {
      cout << G[i][j];
    }
    cout << "\n";
  }
  return 0;
}
