#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  string g;
  vector<string> grid;
  for (int i = 0; i < h; ++i) {
    cin >> g;
    if (g != string(w, '.')) 
      grid.push_back(g);
  }
  vector<string> res;
  h = grid.size();
  for (int i = 0; i < w; ++i) {
    string col;
    for (int j = 0; j < h; ++j) {
      col += grid[j][i];
    }
    if (col != string(h, '.')) 
      res.push_back(col);
  }

  for (int i = 0; i < res[0].size(); ++i) {
    for (int j = 0; j < res.size(); ++j) {
      cout << res[j][i];
    }
    cout << endl;
  }

  return 0;
}

