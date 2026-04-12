#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

ll f[1000100], finv[1000100];

ll modpow(ll a,ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a) {
  return modpow(a, mod - 2);
}

ll nCr(ll n, ll r) {
  if (r < 0 || r > n) return 0;
  return f[n] * finv[n - r] % mod * finv[r] % mod;
}

ll nHr(ll n, ll r) {
  return nCr(n + r - 1, r);
}

void init() {
  f[0] = 1, finv[0] = 1;
  FOR(i, 1, 1000100) {
    f[i] = i * f[i - 1] % mod;
    finv[i] = modinv(f[i]);
  }
}

ll dp[1005][1005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  init();

  ll n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  dp[a - 1][n] = 1;
  FOR(i, a, b + 1) {
    rep(j, n + 1) {
      dp[i][j] = dp[i - 1][j];
      ll res = 1;
      FOR(k, 1, c) res = res * nCr(j + i * k, i) % mod;
      FOR(k, c, d + 1) {
        if (j + i * k > n) break;
        res = res * nCr(j + i * k, i) % mod % mod;
        dp[i][j] = (dp[i][j] + dp[i - 1][j + i * k] * res % mod * finv[k]) % mod;
      }
    }
  }
  cout << dp[b][0] << '\n';
  




  
  return 0;
}