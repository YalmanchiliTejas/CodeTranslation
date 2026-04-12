#include <bits/stdc++.h>
using namespace std;

const unsigned long mod = 998244353;
long n;
long f;
long g[10000001];
long p[10000001];

long power(long b, long e) {
  if (e == 0) return 1;
  if (e % 2 == 1) return power(b, e - 1) * b % mod;
  long t = power(b, e / 2);
  return t * t % mod;
}

long inv(long n) {
  return power(n, mod - 2);
}

void pre() {
  p[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] * 2;
    if (p[i] >= mod) p[i] -= mod;
  }
  f = 1;
  for (int i = 1; i <= n; ++i) {
    f = f * i % mod;
  }
  g[n] = inv(f);
  for (int i = n; i >= 1; --i) {
    g[i - 1] = g[i] * i % mod;
  }
}

long sub(long k) {
  return p[n - k] * g[k] % mod * g[n - k] % mod;
}

int main() {
  cin >> n;
  pre();
  long sum = 0;
  for (int k = n; 2 * k > n; --k) {
    sum += sub(k);
    if (sum >= mod) sum -= mod;
  }
  cout << (power(3, n) - 2 * f * sum % mod + mod) % mod << endl;
}