#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> g(h, vector<char>(w, '.'));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) cin >> g[i][j];
  }

  vector<bool> sr(h, false);
  for (int i = 0; i < h; i++) {
    bool skip = true;
    for (int j = 0; j < w; j++) {
      if (g[i][j] == '#') skip = false;
    }
    sr[i] = skip;
  }

  vector<bool> sc(w, false);
  for (int j = 0; j < w; j++) {
    bool skip = true;
    for (int i = 0; i < h; i++) {
      if (g[i][j] == '#') skip = false;
    }
    sc[j] = skip;
  }

  for (int i = 0; i < h; i++) {
    if (sr[i]) continue;
    for (int j = 0; j < w; j++) {
      if (!sc[j]) cout << g[i][j];
    }
    cout << endl;
  }
}
