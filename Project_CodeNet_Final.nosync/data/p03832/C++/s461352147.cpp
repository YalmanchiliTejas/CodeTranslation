#include <bits/stdc++.h>
     
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int N = 1e3 + 5;

ll dp[N][N];
int n;
ll A, B, C, D;
ll f[N], inv[N];

ll ncr(ll n, ll r) {
  if(n < r or n < 0 or r < 0) return 0;
  ll res = (inv[n - r] * inv[r]) % mod;
  res = (res * f[n]) % mod;
  return res;
}

ll bigmod(ll a, ll b) {
  ll res = 1LL;
  while(b) {
    if(b & 1LL) res = (res * a) % mod;
    b >>= 1LL;
    a = (a * a) % mod;
  }
  return res;
}

ll go(int cur, int sum) {
  if(cur == B + 1) return sum == n;
  if(dp[cur][sum] != -1) return dp[cur][sum];
  ll ways = 0;
  ways = (ways + go(cur + 1, sum)) % mod;
  for(ll c = C; c <= D; c++) {
    if(c * cur + sum > n) break;
    ll facto = bigmod(inv[cur], c);
    ll mul = (ncr(n - sum, c * cur) * f[c * cur]) % mod;
    mul = (mul * facto) % mod;
    mul = (mul * inv[c]) % mod;
    ways = (ways + mul * go(cur + 1, c * cur + sum) % mod) % mod;
  }
  return dp[cur][sum] = ways;
}

int main() {
  f[0] = 1;
  for(ll i = 1; i < N; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
  inv[N - 1] = bigmod(f[N - 1], mod - 2);
  inv[0] = 1;
  for(ll i = N - 2; i >= 0; i--) {
    inv[i] = (inv[i + 1] * (i + 1)) % mod;
  }
  cin >> n >> A >> B >> C >> D;
  memset(dp, -1, sizeof dp);
  cout << go(A, 0);
}
