#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define DEBUGP(val) cerr << #val << "=" << val << "\n"



const int DEBUG = 0;

using namespace std;
typedef long long int lint;
typedef pair<int, lint> pil;
typedef pair<lint, int> pli;
typedef pair<lint, lint> pll;
const lint mod = 1e9 + 7;

const lint inf = 1e18;

lint sq(lint x) { return x * x % mod; }

const int N = 100100;
int n;
vector<pil> edges[N];

pll add(pll a, pll b) {
  if (a.first != b.first) return min(a,b);
  return pll(a.first,(a.second+b.second)%mod);
}
pll mul(pll a,pll b){
  return pll(a.first+b.first,a.second*b.second%mod);
}


vector<pll> calc(int s) {
  vector<pll> dp(n, pll(inf, 0));
  vector<bool> vis(n, false);
  priority_queue<pli, vector<pli> , greater<pli> > que;
  dp[s] = pll(0, 1);
  que.push(pli(0, s));
  while (not que.empty()) {
    pli vd = que.top(); que.pop();
    int v = vd.second;
    if (vis[v]) continue;
    vis[v] = true;
    REP(i, 0, edges[v].size()) {
      pil wc = edges[v][i];
      int w = wc.first;
      lint c = wc.second;
      dp[w]=add(dp[w],mul(dp[v],pll(c,1)));
      que.push(pli(dp[w].first,w));
    }
  }
  return dp;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, s, t;
  cin >> n >> m >> s >> t;
  s--, t--;
  REP(i, 0, m) {
    int u, v, d;
    cin >> u >> v >> d;
    u--, v--;
    edges[u].push_back(pil(v, d));
    edges[v].push_back(pil(u, d));
  }
  vector<pll> sol_s, sol_t;
  sol_s = calc(s);
  sol_t = calc(t);
  if (DEBUG) {
    cerr << "dp:";
    REP(i, 0, n) cerr << " " << sol_s[i].second;
    cerr << endl;
    cerr << "dp2:";
    REP(i, 0, n) cerr << " " << sol_t[i].second;
    cerr << endl;
  }
  lint ans = sq(sol_s[t].second);
  REP(i, 0, n) {
    if (sol_s[i].first + sol_t[i].first != sol_s[t].first) continue;
    if (2 * sol_s[i].first == sol_s[t].first) {
      ans += mod - sq(sol_s[i].second * sol_t[i].second % mod);
      ans %= mod;
    }
    if (2 * sol_s[i].first < sol_s[t].first) {
      REP(j, 0, edges[i].size()) {
	pil wc = edges[i][j];
	int w = wc.first;
	lint c = wc.second;
	if (sol_s[i].first + c + sol_t[w].first != sol_s[t].first) continue;
	if (2 * sol_s[w].first > sol_s[t].first) {
	  ans += mod - (sq(sol_s[i].second * sol_t[w].second % mod) % mod);
	  ans %= mod;
	}
      }
    }
  }
  cout << ans << endl;
}
