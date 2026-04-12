#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> m(h + 2);
  for (int i = 1; i <= h; i++) cin >> m[i];

  for (int i = 1; i <= h; i++) m[i] = '.' + m[i] + '.';
  string d(w + 2, '.');
  m[h + 1] = d;
  m[0] = d;

  bool ans = true;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (m[i][j] == '.') continue;
      if ((m[i + 1][j] == '#' && m[i][j + 1] == '#') ||
          (m[i - 1][j] == '#' && m[i][j - 1] == '#')) {
        ans = false;
        break;
      }
    }
  }
  if (ans) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
}
