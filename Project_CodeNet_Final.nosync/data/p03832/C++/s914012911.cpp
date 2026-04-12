#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, n) for (int i = (a); i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define FOR(it, c) \
  for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

ll mod_inverse(ll a, ll m) {
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}

ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll res = mod_pow(x * x % mod, n / 2, mod);
  if (n & 1) res = res * x % mod;
  return res;
}

static const ll MOD = 1000000007;
ll fact[1005];
ll dp[1005][1005];
int N, A, B, C, D;

ll f(int i, int j, int x) {
  if (x == 0) return 1;
  if (N - j + i * x < i * x) return 0;
  ll ret1 = fact[N - j + i * x];
  ll ret2 = fact[N - j];
  ret2 %= MOD;
  ret2 *= mod_pow(fact[i], x, MOD);
  ret2 %= MOD;
  ret2 *= fact[x];
  ret2 %= MOD;
  return ret1 * mod_inverse(ret2, MOD) % MOD;
}

int main() {
  ll p = 1;
  fact[0] = 1;
  REP(i, 1, 1005) {
    p *= i;
    p %= MOD;
    fact[i] = p;
  }

  cin >> N >> A >> B >> C >> D;

  dp[0][0] = 1;
  REP(i, 1, N + 1) {
    rep(j, N + 1) {
      dp[i][j] = dp[i - 1][j];
      if (A <= i && i <= B) {
        REP(x, C, D + 1) {
          if (j - i * x < 0) break;
          dp[i][j] += f(i, j, x) * dp[i - 1][j - i * x] % MOD;
          dp[i][j] %= MOD;
        }
      }
    }
  }

  cout << dp[N][N] << endl;

  return 0;
}
