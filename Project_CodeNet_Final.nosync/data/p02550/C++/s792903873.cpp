#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int64 Solve() {
  int64 n, x, m;
  cin >> n >> x >> m;
  if (n < 1E6) {
    vector<int64> xs(n);
    xs[0] = x;
    for (int i = 1; i < n; i++) {
      xs[i] = xs[i - 1] * xs[i - 1] % m;
    }

    int64 sum = 0;
    for (int i = 0; i < n; i++) {
      sum += xs[i];
    }
    return sum;
  }


  vector<int64> xs(2 * m, -1);
  vector<int> indexes(m, -1);
  xs[0] = x;
  indexes[x] = 0;
  for (int i = 1 ; i < 2 * m; i++) {
    // cout << "i: " << i << endl;
    xs[i] = xs[i - 1] * xs[i - 1] % m;
    if (indexes[xs[i]] == -1) {
      indexes[xs[i]] = i;
    } else {
      int64 a = indexes[xs[i]];
      // cout << "a: " << a << endl;
      int64 c = i - a;
      int64 q = (n - a) / c;
      int64 r = (n - a) % c;

      int64 sum = 0;
      for (int i = 0; i < a; i++) {
        sum += xs[i];
      }
      int64 cycle_sum = 0;
      for (int i = a; i < a + c; i++) {
        cycle_sum += xs[i];
      }
      sum += cycle_sum * q;
      for (int i = a; i < a + r; i++) {
        sum += xs[i];
      }
      return sum;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << Solve() << endl;
}