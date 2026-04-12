#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> track(n);
  for (int i = 0; i < n; ++i) {
    cin >> track[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (track[i][j] == '#' && track[i + 1][j] == '#' && track[i][j + 1] == '#') {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (track[i][j] == '#' && track[i - 1][j] == '#' && track[i][j - 1] == '#') {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;

  return 0;
}