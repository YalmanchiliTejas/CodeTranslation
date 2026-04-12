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
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

// NOTE : use H with larger N
/// --- Modulo Factorial {{{ ///
#include <cassert>
#include <cstddef>
template < std::size_t N, int mod = static_cast< int >(1e9 + 7) >
struct Factorial {
  using integer = long long;
  constexpr integer extgcd(integer a, integer b, integer &x, integer &y) {
    integer d = 0;
    return b == 0 ? (x = a < 0 ? -1 : 1, y = 0, a < 0 ? -a : a)
      : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
  }
  constexpr integer modinv(integer a) {
    integer x = 0, y = 0;
    extgcd(a, mod, x, y);
    if(x < 0)
      x += mod;
    else if(x == mod)
      x = 0;
    return x;
  }
  int arr[N + 1], inv[N + 1];
  integer operator[](int i) const { return arr[i]; }
  Factorial() : arr(), inv() {
    arr[0] = 1;
    for(std::size_t i = 1; i <= N; i++) {
      arr[i] = (integer) i * arr[i - 1] % mod;
    }
    inv[N] = modinv(arr[N]);
    for(int i = N - 1; i >= 0; i--) {
      inv[i] = (integer)(i + 1) * inv[i + 1] % mod;
    }
  }
  integer C(int n, int r) const {
    if(n < 0 || r < 0 || n < r) return 0;
    assert(n <= N);
    return (integer) arr[n] * inv[r] % mod * inv[n - r] % mod;
  }
  integer H(int n, int r) const { return C(n + r - 1, r); }
};
/// }}}--- ///

constexpr int mod = 1e9 + 7;
const int N = 2e5 + 10;
Factorial< N * 2, mod > fact;

ll sum[212345];

int inv2 = 500000004;

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  if(n > m) swap(n, m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) for(int k = 0; k < m; k++) {
      sum[abs(i - j)]++;
      sum[abs(i - j) + 1]++;
      sum[abs(i - j) + k + 1]--;
      sum[abs(i - j) + (m - 1 - k) + 1]--;
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n + m; i++) {
    sum[i] += sum[i-1];
    sum[i] %= mod;

    ans += i * sum[i] % mod;
  }
  ans %= mod;
  ans = ans * inv2 % mod;

  ans = ans * fact.C(n * m - 2, k - 2) % mod;

  cout << ans << endl;

  return 0;
}
