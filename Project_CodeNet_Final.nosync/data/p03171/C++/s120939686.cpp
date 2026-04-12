#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 3e3+23;

int n;
long long a[N], dp[N][N];

long long rek(int l, int r) {
  if (l > r) {
    return 0;
  }
  long long &ret = dp[l][r];
  if (ret != -1) return ret;
  int taken = l+(n-r-1);
  if (taken&1) {
    ret = min(rek(l+1, r)-a[l], rek(l, r-1)-a[r]);
  } else {
    ret = max(a[l]+rek(l+1, r), a[r]+rek(l, r-1));
  }
  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", a+i);
  printf("%lld", rek(0, n-1));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
