#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;

  vector<bool> rows(h, false), cols(w, false);

  vector<vector<char>> a(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char s;
      cin >> s;

      if (s == '#') {
        rows.at(i) = true;
        cols.at(j) = true;
      }

      a.at(i).at(j) = s;
    }
  }

  for (int i = 0; i < h; i++) {
    if (!rows.at(i)) continue;

    for (int j = 0; j < w; j++) {
      if (!cols.at(j)) continue;

      cout << a.at(i).at(j);
    }

    cout << endl;
  }

  return 0;
}