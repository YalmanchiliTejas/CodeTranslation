#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-12, PI = acos(-1);
const int N = 1e6 + 9, M = 5e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

ll mul(ll a, ll b) {
  return (a * b) % MOD;
}

ll add(ll a, ll b) {
  a += b;
  if(a >= MOD)
    a -= MOD;
  if(a < 0)
    a += MOD;
  return a;
}

ll power(ll a, ll b) {
  ll ret = 1;
  while(b) {
    if(b & 1)
      ret = mul(ret, a);
    b /= 2;
    a = mul(a, a);
  }
  return ret;
}

ll fact[N], invFact[N];

ll C(int n, int r) {
  return mul(fact[n], mul(invFact[n-r], invFact[r]));
}

int main() {
  fastIO;
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
#endif
  fact[0] = 1, fact[1] = 1, invFact[0] = 1, invFact[1] = 1;
  for (int i = 2; i < N; ++i) {
    fact[i] = mul(fact[i-1], i);
    invFact[i] = power(fact[i] ,MOD - 2);
  }
  int n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    ans = add(ans, mul(mul(i, n - i), mul(m, m)));
  }
  for (int i = 1; i < m; ++i) {
    ans = add(ans, mul(mul(i, m - i), mul(n, n)));
  }
  ans = mul(ans, C(n * m - 2, k - 2));
  cout << ans;
  return 0;
}
