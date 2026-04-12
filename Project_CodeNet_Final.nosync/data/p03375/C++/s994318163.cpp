#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
int modpow(int x, int k, int MOD) {
  int a = 1;
  while (k > 0) {
    if (k & 1) a = (1LL*a*x) % MOD;
    x = (1LL*x*x) % MOD;
    k >>= 1;
  }
  return a;
}

int N, MOD;
int nCr[3001][3001];
int fact[3001];
int dp[3001][3001];
inline int mul(int x, int y) { return (1LL*x*y)%MOD; }
inline void add(int &x, int v) { x += v; if (x >= MOD) x -= MOD; }

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> MOD;

  nCr[0][0] = 1;
  for (int i=1; i<=3000; i++) {
    nCr[i][0] = 1;
    for (int j=1; j<=3000; j++) nCr[i][j] = (nCr[i-1][j-1]+nCr[i-1][j])%MOD;
  }
  fact[0] = 1;
  for (int i=1; i<=3000; i++) fact[i] = (1LL*i*fact[i-1])%MOD;

  dp[0][0] = 1;
  rep(i, 3000) {
    rep(y, i+1) {
      add(dp[i+1][y+1], dp[i][y]);
      add(dp[i+1][y], mul(y+1, dp[i][y]));
    }
  }

  int sum = 0;
  for (int S=0; S<=N; S++) {
    int base = modpow(2, N-S, MOD);
    int s = 0;
    int w = 1; // base^num
    rep(num, S+1) {
      add(s, mul(dp[S][num], w));
      w = mul(w, base);
    }
    s = mul(s, modpow(2, modpow(2, N-S, MOD-1), MOD));
    s = mul(s, nCr[N][S]);
    if (S%2) s = (MOD-s)%MOD;
    sum = (sum+s)%MOD;
  }
  cout << sum << "\n";
  return 0;
}
