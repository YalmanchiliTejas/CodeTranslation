#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> in(h);
  for (int i = 0; i < h; i++) cin >> in[i];
  in.push_back("");
  for (int j = 0; j < w; j++) {
    if (j == w - 1) in[h].push_back('#');
    else in[h].push_back('.');
  }
  int c = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < c; j++) {
      if (in[i][j] == '#') {
        cout << "Impossible\n";
        return 0;
      }
    }
    for (int j = c; j < w; j++) {
      if (in[i + 1][j] == '#') {
        c = j;
        break;
      }
    }
    for (int j = c + 1; j < w; j++) {
      if (in[i][j] == '#') {
        cout << "Impossible\n";
        return 0;
      }
    }
  }
  cout << "Possible\n";
  return 0;
}