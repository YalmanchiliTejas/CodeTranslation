
#include <bits/stdc++.h>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ull MAX_N = 1000, MOD = 1e9+7;
ull N, A, B, C, D;
ull dp[MAX_N+1][MAX_N+1];
ull fact[MAX_N+1];
ull inv_fact[MAX_N+1];
ull inv_fact_pow[MAX_N+1];

//整数a,bに対し、ax + by = gcd(a,b) を満たす整数x,y,gcd(a,b) を計算する
ll extgcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if (b != 0) {
    d = extgcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

//ax ≡ gcd(a,m) (mod m) を満たすxを計算する。
ll mod_inverse(ll a, ll m) {
  ll x, y;
  extgcd(a, m, x, y);
  return (m + x%m) % m;
}

void calc_fact(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (fact[i-1]*i)%MOD;
  }
}

void calc_inv_fact(int n) {
  for (int i = 0; i <= n; ++i) {
    inv_fact[i] = mod_inverse(fact[i], MOD);
  }
}

void calc_inv_fact_pow(int n, int c) {
  for (int k = 1; k <= n; ++k) {
    inv_fact_pow[k] = 1;
    for (int i = 1; i < c; ++i) {
      (inv_fact_pow[k] *= inv_fact[k]) %= MOD;
    }
  }
}


int main() {
  cin >> N >> A >> B >> C >> D;
  calc_fact(N);
  calc_inv_fact(N);
  calc_inv_fact_pow(N, C);


  for (int k = 0; k <= N; ++k) dp[k][0] = 1;
  for (int k = 1; k <= N; ++k) {
    for (int n = 1; n <= N; ++n) {
      if (A <= k && k <= B) {
        dp[k][n] = dp[k-1][n];
        ull t = inv_fact_pow[k];
        for (int x = C; x <= D; ++x) {
          if (n-k*x < 0) break;
          (t *= inv_fact[k]) %= MOD;
          (dp[k][n] += dp[k-1][n-k*x] * fact[n] % MOD * inv_fact[n-k*x] % MOD * t % MOD * inv_fact[x] % MOD) %= MOD;
        }
      } else {
        dp[k][n] = dp[k-1][n];
      }
    }
  }

  cout << dp[N][N] << endl;

  return 0;
}
