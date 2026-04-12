#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<char>> r(h, vector<char>(w));
  vector<vector<char>> c(w, vector<char>(h));
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      cin >> r[i][j];
      c[j][i] = r[i][j];
    }
  vector<bool> row(h);
  for (int i = 0; i < h; i++)
    if (count(r[i].begin(), r[i].end(), '.') == w)
      row[i] = true;
  vector<bool> col(w);
  for (int i = 0; i < w; i++)
    if (count(c[i].begin(), c[i].end(), '.') == h)
      col[i] = true;
  for (int i = 0; i < h; i++) {
    bool has = false;
    for (int j = 0; j < w; j++) {
      if (row[i] || col[j])
        continue;
      has = true;
      cout << r[i][j];
    }
    if (has)
      cout << '\n';
  }
  return 0;
}