#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

#define INF 10e17 // 4倍しても(4回足しても)long longを溢れない
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

ll dp[100010][101][2];

ll solve(string &k, int d) {
  dp[0][0][0] = 1;
  ll size = k.length();

  int now;
  rep(i, size) rep(j, d) {
    now = k[i] - '0';

    rep(l, 10) {
      if (l < now) {
        dp[i + 1][(l + j) % d][1] += (dp[i][j][0] + dp[i][j][1]) % MOD;
        dp[i + 1][(l + j) % d][1] %= MOD;
      } else if (l == now) {
        dp[i + 1][(l + j) % d][0] += dp[i][j][0];
        dp[i + 1][(l + j) % d][0] %= MOD;
        dp[i + 1][(l + j) % d][1] += dp[i][j][1];
        dp[i + 1][(l + j) % d][1] %= MOD;
      } else {
        // l > now
        dp[i + 1][(l + j) % d][1] += dp[i][j][1];
        dp[i + 1][(l + j) % d][1] %= MOD;
      }
    }
  }

  return (dp[size][0][0] + dp[size][0][1] - 1 + MOD) % MOD;
}

int main() {
  string k;
  int d;

  cin >> k >> d;
  cout << solve(k, d) << endl;
}
