#include <cstdio>
#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)

ll const INF = 1000000000000000000;
int const I_MAX = 2147483647;
ll const MOD = 1e9 + 7;
int const POW_MAX = 1e5;

ll po[POW_MAX + 2];

ll mod_pow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}

ll mod_inv (ll x) {
  return mod_pow(x, MOD - 2) % MOD;
}

ll comb(int n, int r) {
  return (((po[n] * mod_inv(po[r])) % MOD) * mod_inv(po[n - r])) % MOD;
}

int N;
ll X;
ll b[51], p[51];

int main() {
  scanf("%d %lld", &N, &X);

  b[0] = 1;
  p[0] = 1;
  FOR(i, 1, N + 1) {
    b[i] = 3 + b[i - 1] * 2;
    p[i] = 1 + p[i - 1] * 2;
  }

  ll eat = 0;
  int n = N;
  while (n >= 0) {
    if (n == 0) {
      if (X > 0) eat++;
      break;
    }

    ll piv = b[n] / 2 + 1;
    if (X == piv) {
      eat += p[n - 1] + 1;
      break;
    } else if (X > piv) {
      eat += p[n - 1] + 1;
      X -= piv;
      n--;
    } else {
      X--;
      n--;
    }
  }
  printf("%lld\n", eat);
}
