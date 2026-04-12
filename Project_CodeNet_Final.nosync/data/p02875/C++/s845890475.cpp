#include <iostream>

using namespace std;

const long long mod = 998244353LL;

int n;

long long pw(long long a, long long b) {
  if (b == 0LL) return 1LL;
  long long r = pw(a, b >> 1);
  r = (r * r) % mod;
  if (b & 1LL) r = (a * r) % mod;
  return r;
}

long long inv(long long x) {
  return pw(x, mod-2LL);
}

int main() {
  cin >> n;

  long long ans = 1LL;
  for (int i = 0; i < n; ++i) ans = (3 * ans) % mod;

  long long val = 1LL, sum = 0LL;
  for (int i = n; i > n/2; --i) {
    sum = (sum + 2 * val) % mod;
    val = (val * i % mod * inv(n-i+1)) % mod;
    val = (val * 2) % mod;
  }

  ans = (ans - sum) % mod;
  ans = (ans % mod + mod) % mod;

  cout << ans << endl;

  return 0;
}
