#include <bits/stdc++.h>
using namespace std;
#define SZ(a) ((int)(a).size())
typedef long long int64;
int main() {
#ifdef LOCAL
  freopen(".a.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
  int64 n, x, m;
  cin >> n >> x >> m;
  vector<int64> A(2 * m), vis(2 * m, -1);
  A[1] = x;
  vis[A[1]] = 1;
  int fx = -1;
  for (int i = 2; i <= n; ++i) {
    A[i] = A[i - 1] * A[i - 1] % m;
    if (vis[A[i]] != -1) {
      fx = i;
      break;
    } else {
      vis[A[i]] = i;
    }
  }
  int64 res = 0;
  if (fx == -1) {
    for (int i = 1; i <= n; ++i) res += A[i];
  } else {
    for (int i = 1; i < vis[A[fx]]; ++i) res += A[i];
    int64 y = 0;
    for (int i = vis[A[fx]]; i < fx; ++i) y += A[i];
    n -= vis[A[fx]] - 1;
    res += n / (fx - vis[A[fx]]) * y;
    n %= fx - vis[A[fx]];
    for (int i = 0; i < n; ++i) res += A[vis[A[fx]] + i];
  }
  cout << res;

  return 0;
}
//2020.09.19 20:16:28
