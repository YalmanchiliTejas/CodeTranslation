#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long mem[1005][1005];
bool vis[1005][1005];
int a, b, c, d;
long long fact[1005], inv[1005];
long long bigpow(long long b, long long p) {
  if (p == 0) return 1;
  long long t = bigpow(b, p / 2);
  t *= t;
  t %= MOD;
  if (p % 2 == 1) {
    t *= b;
    t %= MOD;
  }
  return t;
}
long long biginv(long long x) {
  return bigpow(x, MOD - 2);
}
long long dp(int x, int y) {
  if (x == 0) return 1;
  if (y > b) return 0;
  if (vis[x][y]) return mem[x][y];
  vis[x][y] = true;
  long long ret = dp(x, y + 1);
  for (int z = c; z <= d && y * z <= x; z++) {
    long long t = dp(x - y * z, y + 1);
    t *= fact[x];
    t %= MOD;
    t *= inv[x - y * z];
    t %= MOD;
    for (int j = 0; j < z; j++) {
      t *= inv[y];
      t %= MOD;
    }
    t *= inv[z];
    t %= MOD;
    ret += t;
  }
  return mem[x][y] = (ret % MOD);
}
int main() {
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= 1000; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = biginv(fact[i]);
  }
  int n;
  cin >> n >> a >> b >> c >> d;
  cout << dp(n, a) << endl;
  return 0;
}
