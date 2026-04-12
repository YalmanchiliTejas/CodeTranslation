#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  string s[h];
  for (int i = 0; i < h; i++) cin >> s[i];
  pair<int, int> koma(0, 0);
  s[0][0] = '.';
  while (koma.first < h - 1 or koma.second < w - 1) {
    if (koma.first < h - 1 and s[koma.first + 1][koma.second] == '#') {
      koma.first++;
      s[koma.first][koma.second] = '.';
      continue;
    }
    if (koma.second < w - 1 and s[koma.first][koma.second + 1] == '#') {
      koma.second++;
      s[koma.first][koma.second] = '.';
      continue;
    }
    break;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] != '.') {
        cout << "Impossible" << "\n";
        return 0;
      }
    }
  }
  cout << "Possible" << "\n";
  return 0;
}