#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);

  int prod = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);

    ans = (ans + 1LL * a[i] * prod) % MOD;
    prod = (prod + a[i]) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
