#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int n;
  while (cin >> n, n) {
    vector<vector<int>> a(n, vector<int>(n));
    int y = n / 2 + 1, x = n / 2;
    for (int i = 1; i <= n * n; i++) {
      if (a[y][x] > 0) {
        (y += 1) %= n;
        (x += 1) %= n;
        if (a[y][x] > 0) {
          (y += 1) %= n;
          (x += n - 1) %= n;
        }
      }
      a[y][x] = i;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << setw(4) << a[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
