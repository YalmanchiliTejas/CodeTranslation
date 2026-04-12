#include <cstdio>
#include <cmath>
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
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)

ll const INF = 1000000000000000000;
int const I_MAX = 2147483647;
ll const MOD = 1e9 + 7;
int const POW_MAX = 1e5;

// nCr
map<ll, ll> po;
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
ll comb(ll n, ll r) {
  if (!po[n]) {
    po[0] = 1;
    FOR(i, 1, n + 1) po[i] = po[i - 1] * i % MOD;
  }
  return (((po[n] * mod_inv(po[r])) % MOD) * mod_inv(po[n - r])) % MOD;
}
// greatest common divisor
ll gcd(ll a, ll b) {
  while (a % b != 0) {
    ll tmp = a;
    a = b;
    b = tmp % b;
  }
  return b;
}

int N, M;
ll K;

int main() {
  scanf("%d %d %lld", &N, &M, &K);

  ll comb_v = comb(N * M - 2, K - 2);

  ll sum = 0;
  FOR(i, 1, N) {
    ll m = (N - i) * M * M % MOD;
    sum += i * m * comb_v % MOD;
    sum %= MOD;
  }
  FOR(i, 1, M) {
    ll m = (M - i) * N * N % MOD;
    sum += i * m * comb_v % MOD;
    sum %= MOD;
  }
  printf("%lld\n", sum);
}
