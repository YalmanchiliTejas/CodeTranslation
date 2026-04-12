#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAXN = 3010;
const int mod = 998244353;
inline ll mul(ll a) { return a; }
template<typename... T> inline ll mul(ll a, T... b) { return (int) ((ll) a * (ll) mul(b...) % mod); }
inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}
ll dp[MAXN][MAXN];
int ar[MAXN];
int n, k;

void add(ll &x, ll y) {
  x += mod;
  y += mod;
  x = (x + y) % mod;
}

ll rec(int i, int sum) {
  if(sum == k) return n - i + 1;
  if(i == n || sum > k) return 0;
  ll &res = dp[i][sum];
  if(res != -1) return res;
  ll a = rec(i + 1, sum);
  ll b = rec(i + 1, sum + ar[i]);
  res = 0;
  add(res, a); add(res, b);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(dp, -1, sizeof dp);
  cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> ar[i];
  rec(0, 0);
  ll res = 0;
  for(int i = 0; i < n; ++i) {
    add(res, rec(i, 0));
  }
  cerr << rec(0, 0) << '\n';
  cout << res << '\n';
  return 0;
}
