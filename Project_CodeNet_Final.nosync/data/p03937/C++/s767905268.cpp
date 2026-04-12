#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int mvx[] = {0, 1}, mvy[] = {1, 0};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 2, vector<int>(m + 2));
  vector<vector<bool>> vv(n + 2, vector<bool>(m + 2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      char c;
      cin >> c;
      if (c == '#')
        v[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i == 1 && j == 1) {
        if (v[i + 1][j] + v[i][j + 1] == 1) {
          continue;
        }
      } else if (i == n && j == m) {
        if (v[i - 1][j] + v[i][j - 1] == 1) {
          continue;
        }
      }
      if (v[i][j]) {
        if (v[i - 1][j] + v[i][j - 1] == 1 && v[i + 1][j] + v[i][j + 1] == 1) {
          continue;
        }
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
}
