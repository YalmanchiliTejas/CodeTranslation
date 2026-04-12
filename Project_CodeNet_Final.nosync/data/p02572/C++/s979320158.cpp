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

const int N = 2e5+23;
const int mod = 1e9+7;

int a[N], c[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  long long ans = 0;
  for (int i = n-2; i >= 0; --i) {
    ans = (ans + 1LL*a[i]*a[i+1]) % mod;
    a[i] = (a[i] + a[i+1]) % mod;
  }
  printf("%lld", ans);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
