#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    vector<vector<int>> m(n, vector<int>(n, -1));
    int x = n / 2, y = n / 2 + 1;
    for (int i = 1; i <= n * n; ++i, ++x, ++y) {
      x %= n;
      y %= n;
      while (~m[y][x]) {
        y = (y + 1) % n;
        x = (x - 1 + n) % n;
      }

      m[y][x] = i;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        printf("%4d", m[i][j]);
      }
      puts("");
    }
  }
}