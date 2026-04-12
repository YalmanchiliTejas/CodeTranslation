#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i, j, l;
  string s, ans = "-1";
  cin >> n >> s;
  vector<string> t(4);
  t[0] = "SS";
  t[1] = "SW";
  t[2] = "WS";
  t[3] = "WW";
  for (i = 0; i < n - 2; ++i) {
    for (j = 0; j < 4; ++j) {
      if (s[i + 1] == 'o') {
        if (t[j][i] == t[j][i + 1]) {
          t[j].push_back('S');
        } else {
          t[j].push_back('W');
        }
      } else {
        if (t[j][i] != t[j][i + 1]) {
          t[j].push_back('S');
        } else {
          t[j].push_back('W');
        }
      }
    }
  }
  for (j = 0; j < 4; ++j) {
    if (s[0] == 'o' && s[n - 1] == 'o') {
      if ((t[j][0] == t[j][n - 1] && t[j][1] == 'S' && t[j][n - 2] == 'S') ||
          (t[j][0] != t[j][n - 1] && t[j][1] == 'W' && t[j][n - 2] == 'W')) {
        ans = t[j];
        break;
      }
    } else if (s[0] == 'o' && s[n - 1] == 'x') {
      if ((t[j][0] == t[j][n - 1] && t[j][1] == 'S' && t[j][n - 2] == 'W') ||
          (t[j][0] != t[j][n - 1] && t[j][1] == 'W' && t[j][n - 2] == 'S')) {
        ans = t[j];
        break;
      }
    } else if (s[0] == 'x' && s[n - 1] == 'o') {
      if ((t[j][0] == t[j][n - 1] && t[j][1] == 'W' && t[j][n - 2] == 'S') ||
          (t[j][0] != t[j][n - 1] && t[j][1] == 'S' && t[j][n - 2] == 'W')) {
        ans = t[j];
        break;
      }
    } else {
      if ((t[j][0] == t[j][n - 1] && t[j][1] == 'W' && t[j][n - 2] == 'W') ||
          (t[j][0] != t[j][n - 1] && t[j][1] == 'S' && t[j][n - 2] == 'S')) {
        ans = t[j];
        break;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}