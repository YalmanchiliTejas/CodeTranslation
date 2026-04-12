#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N, A, B, C, D;
int dp[1001][1001];
int fact[1001];
int factinv[1001];
int comb[1001][1001];

int modpow(int x, int k) {
  int a = 1;
  while (k > 0) {
    if (k & 1) a = (1LL*a*x) % MOD;
    x = (1LL*x*x) % MOD;
    k >>= 1;
  }
  return a;
}

int inv(int x) {
  return modpow(x, MOD-2);
}

int nCr(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return (1LL * fact[n] * inv((1LL*fact[k]*fact[n-k]) % MOD)) % MOD;
}

int f(int x, int n) {
  if (dp[x][n] != -1) return dp[x][n];
  if (n == 0) return dp[x][n] = 1;
  if (x < A) return dp[x][n] = 0;
  long long s = 0;
  s += f(x-1, n);
  int y = 1;
  for (int k=1; k<C; k++) {
    if (n-k*x < 0) break;
    y = (1LL * y * comb[n-(k-1)*x][x]) % MOD;
  }
  for (int k=C; k<=D; k++) {
    if (n-k*x < 0) break;
    y = (1LL * y * comb[n-(k-1)*x][x]) % MOD;
    int b = (1LL * y * factinv[k]) % MOD;
    s = (s + 1LL * b * f(x-1, n-k*x)) % MOD;
  }
  return dp[x][n] = s;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> A >> B >> C >> D;
  fact[0] = 1;
  factinv[0] = 1;
  for (int i=1; i<=N; i++) {
    fact[i] = (1LL*i*fact[i-1]) % MOD;
    factinv[i] = inv(fact[i]);
  }
  for (int i=0; i<=1000; i++) {
    for (int j=0; j<=1000; j++) {
      dp[i][j] = -1;
      comb[i][j] = nCr(i, j);
    }
  }

  cout << f(B, N) << "\n";
  return 0;
}
