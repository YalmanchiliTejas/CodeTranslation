#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> g(h);
  vector<int> dy = {1, 0, -1, 0};
  vector<int> dx = {0, 1, 0, -1};
  int nm = 0;
  vector<int> cnt(4);
  for (int i = 0; i < h; ++i) {
    cin >> g[i];
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (g[i][j] == '#') {
        ++nm;
        for (int k = 0; k < 4; ++k) {
          int ni = i + dy[k];
          int nj = j + dx[k];
          if (ni >= 0 && ni < h) {
            if (nj >= 0 && nj < w) {
              if (g[ni][nj] == '#') {
                ++cnt[k];
              }
            }
          }
        }
      }
    }
  }
  if (nm == (h + w - 1) && cnt[0] == h - 1 && cnt[1] == w - 1) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}

