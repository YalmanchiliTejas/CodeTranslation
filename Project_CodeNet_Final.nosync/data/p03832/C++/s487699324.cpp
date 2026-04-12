#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <algorithm>
#include <functional>
#include <utility>
#include <string>
#define int long long int
#define mod(x) ((x % MOD) + MOD) % MOD
#define rep(i,a,b) for(int i=(a);i<(b);++i)

#define vec vector

using namespace std;

const int INF = 1e18;
const int MOD = 1e9+7;
const int MAX_N = 1e3+1;

int frac[MAX_N];
void init_frac(int N) {
  frac[0] = 1;
  for (int i = 1; i <= N; i++) {
    frac[i] = mod(frac[i-1] * i);
  }
}

int powM(int x, int n) {
  int res = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      res = mod(res * x);
    }
    x = mod(x * x);
    n >>= 1;
  }
  return res;
}

int inverse(int x) {
  return powM(x, MOD-2);
}

int perm(int n, int r) {
  if (n < 0 || n-r < 0) {
    return 0;
  }
  return mod(frac[n] * inverse(frac[n-r]));
}


signed main()
{
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

  init_frac(n);
  int dp[MAX_N][MAX_N];
  rep(i, 0, n+1) {
    fill(dp[i], dp[i] + b+1, 0);
  }
  dp[0][a] = 1;
  for (int i = c; i*a <= n && i <= d; i++) {
    dp[i*a][a] = mod(perm(n,i*a) * inverse(powM(frac[a],i) * frac[i]));
  }

  rep(i, 0, n+1) {
    rep(j, a+1, b+1) {
      int s = 0;
      for (int k = c; j*k <= i && k <= d; k++) {
        s = mod(s + mod(dp[i - j*k][j-1] * mod(perm(n-(i-j*k), j*k) * inverse(mod(powM(frac[j],k)*frac[k])))));
      }
      s = mod(s + dp[i][j-1]);

      dp[i][j] = s;
    }
  }

  cout << dp[n][b] << endl;

  return 0;
}
