#include <bits/stdc++.h>
using namespace std;

struct item {
  long long v, p;
};

struct town {
  int x, y, l;
  vector<long long> weights, values;
};

long long n, m, w, t;
map<string, item> mp;
vector<town> towns;
vector<long long> memot, memov;

long long solve();

int main() {
  cin >> n >> m >> w >> t;
  for(int i = 0; i < m; ++i) {
    string s;
    long long v, p;
    cin >> s >> v >> p;
    mp[s] = {v, p};
  }
  towns.resize(n);
  for(int i = 0; i < n; ++i) {
    int l;
    cin >> l >> towns[i].x >> towns[i].y;
    towns[i].l = l;
    towns[i].values.resize(l);
    towns[i].weights.resize(l);
    for(int j = 0; j < l; ++j) {
      string s;
      cin >> s >> towns[i].values[j];
      towns[i].weights[j] = mp[s].v;
      towns[i].values[j] =
          max(0LL, mp[s].p - towns[i].values[j]);
    }
  }
  cout << solve() << endl;
  return 0;
}

long long solve() {
  // calc time bit dp
  {
    memot.assign(1 << n, t + 1);
    vector<vector<long long>> dp(
        1 << n, vector<long long>(n, t + 1));
    for(int i = 1; i < (1 << n); ++i)
      for(int j = 0; j < n; ++j)
        if(i >> j & 1) {
          if((1 << j) == i)
            dp[i][j] = abs(towns[j].x) + abs(towns[j].y);
          else {
            for(int k = 0; k < n; ++k)
              if(j != k && (i >> k & 1))
                dp[i][j] =
                    min(dp[i][j],
                        dp[i - (1 << j)][k] +
                            abs(towns[j].x - towns[k].x) +
                            abs(towns[j].y - towns[k].y));
          }
          memot[i] =
              min(memot[i], dp[i][j] + abs(towns[j].x) +
                                abs(towns[j].y));
        }
  }
  // calc value knapsack dp
  {
    memov.assign(1 << n, 0);
    vector<vector<long long>> dp(
        1 << n, vector<long long>(w + 1, 0));
    for(int i = 1; i < (1 << n); ++i)
      for(int j = 0; j < n; ++j)
        if(i >> j & 1)
          for(int k = 0; k < towns[j].l; ++k)
            for(int p = towns[j].weights[k]; p <= w; ++p) {
              dp[i][p] = max(
                  dp[i][p], dp[i][p - towns[j].weights[k]] +
                                towns[j].values[k]);
              memov[i] = max(memov[i], dp[i][p]);
            }
  }
  // calc max profit
  long long res = 0;
  {
    vector<long long> dp(t + 1, 0);
    for(int i = 1; i < (1 << n); ++i)
      for(int j = memot[i]; j <= t; ++j) {
        dp[j] = max(dp[j], dp[j - memot[i]] + memov[i]);
        res = max(res, dp[j]);
      }
  }
  return res;
}
