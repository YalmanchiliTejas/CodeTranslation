// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
// #include<deque>
// #include<multiset>
// #include<bitset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

// O(N^.5)
/// --- phi {{{ ///
ll phi(ll n) {
  ll res = n;
  for(ll i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      res = res / i * (i - 1);
      while(n % i == 0) n /= i;
    }
  }
  if(n != 1) res = res / n * (n - 1);
  return res;
}
/// }}}--- ///

// WARN : use H with larger N
/// --- Modulo Factorial {{{ ///
template < int N >
struct Factorial {
  int mod;
  ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = 0;
    return b == 0 ? (x = 1, y = 0, a) : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
  }
  ll modinv(ll a) {
    ll x = 0, y = 0;
    extgcd(a, mod, x, y);
    return (x + mod) % mod;
  }
  int arr[N + 1], inv[N + 1];
  ll operator[](int i) const { return arr[i]; }
#if !defined(DEBUG)
  constexpr
#endif
    Factorial(int mod)
    : mod(mod), arr(), inv() {
      arr[0] = 1;
      for(int i = 1; i <= N; i++) {
        arr[i] = (ll) i * arr[i - 1] % mod;
      }
      inv[N] = modinv(arr[N]);
      for(int i = N - 1; i >= 0; i--) {
        inv[i] = (ll)(i + 1) * inv[i + 1] % mod;
      }
    }
  ll C(int n, int r) const {
    if(n < 0 || r < 0 || n < r) return 0;
    return (ll) arr[n] * inv[r] % mod * inv[n - r] % mod;
  }
  ll H(int n, int r) const { return C(n + r - 1, r); }
};
/// }}}--- ///

/// --- math {{{ ///
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d;
  return b == 0 ? (x = 1, y = 0, a) : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
}
ll modinv(ll a, ll mod) {
  ll x, y;
  extgcd(a, mod, x, y);
  if(x < 0) x += mod;
  return x;
}
ll modpow(ll a, ll b, ll mod) {
  ll r = 1;
  a %= mod;
  while(b) {
    if(b & 1) r = r * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}
/// }}}--- ///

constexpr int N = 5000 + 10;
int n, m;

// [i][j] :=
// 区別可能なi個を区別できないj個の箱に入れるか入れないかする方法
// ただしどの箱にも一個以上入っている
// ( = 第二種スターリング数的なもの )
ll S[N][N];

// 指定したi個を違反する (一個以下にしか入っていない状態) ようにする場合の数
ll w[N];

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  Factorial < N * 2 > fact(m);
  S[0][0] = 1;

  for(int i = 1; i <= n; i++) for(int j = 0; j <= i; j++) {
    S[i][j] = (j - 1 >= 0 ? S[i-1][j-1] : 0) + S[i-1][j] * (j + 1) % m;
    S[i][j] %= m;
  }

  ll phim = phi(m);

  for(int x = 0; x <= n; x++) {
    for(int i = 0; i <= x; i++) {
      // j 個が1個どれかに含まれるような通り数
      w[x] += S[x][i] * modpow(2, i * (n - x), m) % m;
    }
    w[x] %= m;
    w[x] = (m - 1 + w[x] * modpow(2, modpow(2, n - x, phim), m) % m) % m;
  }

  ll ans = 0;
  for(int i = 0; i <= n; i++) {
    ans += m + (i & 1 ? -1 : 1) * fact.C(n, i) % m * w[i] % m;
  }

  ans %= m;

  cout << ans << endl;

  return 0;
}
