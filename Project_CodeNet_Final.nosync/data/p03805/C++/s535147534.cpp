#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, m, edge[11][11], dp[1111][11];
int u, v;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  REP (i, m) {
  	cin >> u >> v;
  	u--; v--;
  	edge[u][v] = edge[v][u] = 1;
  }
  dp[1][0] = 1;
  FOR (mask, 2, (1 << n) - 1) REP (i, n) if (mask & (1 << i)) {
  	REP (j, n) if (i != j) if (mask & (1 << j)) if (edge[i][j]) dp[mask][i] += dp[mask ^ (1 << i)][j];
  }
  int ans = 0;
  REP (i, n) ans += dp[(1 << n) - 1][i];
  // REP (i, n) cout << i << ' ' << dp[(1 << n) - 1][i] << endl;
  cout << ans;
}