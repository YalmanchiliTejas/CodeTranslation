// 2020-08-15 12:37:58
#include<bits/stdc++.h>
#define rep(i, n) REP(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
using namespace std;
using ll = long long;

const int mod = 1000000007;
namespace combinatorics {
  const int limit = 200020;
  bool initialized = false;
  long long fac_table[limit], inv_table[limit], finv_table[limit];
  void initialize() {
    fac_table[0] = fac_table[1] = 1;
    inv_table[1] = 1;
    finv_table[0] = finv_table[1] = 1;
    for (int i = 2; i < limit; i++) {
      fac_table[i] = fac_table[i - 1] * i % mod;
      inv_table[i] = mod - inv_table[mod % i] * (mod / i) % mod;
      finv_table[i] = finv_table[i - 1] * inv_table[i] % mod;
    }
    initialized = true;
  }
  long long com(int n, int k) {
    if (!initialized) initialize();
    if (n < k || n < 0 || k < 0) return 0;
    else return fac_table[n] * (finv_table[k] * finv_table[n - k] % mod) % mod;
  }
  long long perm(int n, int k) {
    if (!initialized) initialize();
    if (n < k || n < 0 || k < 0) return 0;
    else return fac_table[n] * finv_table[n - k] % mod;
  }
}
using combinatorics::com;

void answer() {
  int n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  rep(_, 2) {
    rep(i, n) {
      ll cur = i;
      (cur *= n-i) %= mod;
      (cur *= m) %= mod;
      (cur *= m) %= mod;
      (ans += cur) %= mod;
    }
    swap(n, m);
  }
  (ans *= com(n*m-2, k-2)) %= mod;
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}