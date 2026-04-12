#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define FOREQ(i, s, n) for (ll i = (s); i <= (ll)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

ll n, m, w, t;
ll sell[100];
ll weight[100];
char str[1000];

vector<ll> goodBuy[100];
vector<ll> goodWeight[100];
ll px[100];
ll py[100];


ll dist(int i, int j) { return abs(px[i] - px[j]) + abs(py[i] - py[j]); }

ll memo[8][1 << 7];
ll CalcTime(int last, int rest) {
  if (memo[last][rest] != -1) { return memo[last][rest]; }
  ll ret = 1LL << 60;
  if (rest == 0) {
    ret = dist(last, n);
  } else {
    REP(i, n) {
      if (!((rest >> i) & 1)) { continue; }
      int nrest = rest & (~(1 << i));
      ret = min(ret, CalcTime(i, nrest) + dist(last, i));
    }
  }
  return memo[last][rest] = ret;
}

ll dp[10010];
ll CalcRieki(int use) {
  ll ret = 0;
  MEMSET(dp, 0);
  REP(i, n) {
    if (!((use >> i) & 1)) { continue; }
    REP(j, goodBuy[i].size()) {
      REP(k, w) {
        int nw = k + goodWeight[i][j];
        if (nw > w) { break; }
        dp[nw] = max(dp[nw], dp[k] + goodBuy[i][j]);
        ret = max(ret, dp[nw]);
      }
    }
  }
  return ret;
}

ll mainDP[10010];
int main() {
  while (scanf("%lld %lld %lld %lld", &n, &m, &w, &t) > 0) {
    MEMSET(mainDP, 0);
    MEMSET(memo, -1);
    REP(i, 100) { goodBuy[i].clear(); }
    REP(i, 100) { goodWeight[i].clear(); }

    map<string, ll> mapto;
    REP(i, m) {
      scanf("%s %lld %lld", str, &weight[i], &sell[i]);
      mapto[str] = i;
    }
    REP(i, n) {
      ll l;
      scanf("%lld %lld %lld", &l, &px[i], &py[i]);
      REP(j, l) {
        ll b;
        scanf("%s %lld", str, &b);
        ll index = mapto[str];
        goodWeight[i].push_back(weight[index]);
        goodBuy[i].push_back(max(sell[index] - b, 0LL));
      }
    }
    px[n] = 0;
    py[n] = 0;
    ll ans = 0;
    REP(i, 1 << n) {
      ll time = CalcTime(n, i);
      ll rieki = CalcRieki(i);
      REP(k, t) {
        ll nt = k + time;
        if (nt > t) { break; }
        mainDP[nt] = max(mainDP[nt], mainDP[k] + rieki);
        ans = max(ans, mainDP[nt]);
      }
    }
    cout << ans << endl;
  }
}