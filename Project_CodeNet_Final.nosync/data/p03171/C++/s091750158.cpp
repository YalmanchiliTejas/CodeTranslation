#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int n; long long a[N], f[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int l = n; l > 0; --l) {
    f[l][l] = a[l];
    for (int r = l + 1; r <= n; ++r) {
      f[l][r] = max(a[l] - f[l + 1][r], a[r] - f[l][r - 1]);
    }
  }
  cout << f[1][n] << endl;
  return 0;
}

