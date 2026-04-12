#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const double TL = 1.5 * CLOCKS_PER_SEC;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define clr(x, y) memset(x, y, sizeof(x))
#define forn(i, n) for (int i = 0; i < n; i++)
#define LL long long

LL mod = 998244353;
LL dp[3005][3005];
int n, s, a[3005];

int main() {
  //auto start_clock = clock();
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  scanf("%d%d", &n, &s);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  LL ans = 0;
  for(int i = 1; i <= n; i++) {
    int x = a[i - 1];
    for(int j = x + 1; j <= s; j++) {
      dp[i][j] += dp[i - 1][j - x];
      dp[i][j] %= mod;
    }
    dp[i][x] += i;
    dp[i][x] %= mod;

    ans += dp[i][s] * (n - i + 1);
    ans %= mod;

    for(int j = 0; j <= s; j++) {
      dp[i][j] += dp[i - 1][j];
      dp[i][j] %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
