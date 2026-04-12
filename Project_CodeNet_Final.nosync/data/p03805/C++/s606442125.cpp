#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rREP(i, k, n) for (int i = (int)(n)-1; i >= k; i--)

#define fi first 
#define se second

#define vi vector<int>
#define pb push_back
#define mp make_pair

#define pcnt __builtin_popcount

typedef long long ll;

const int inf = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;

int n, m;
vector<vector<int>> g(10,vector<int>(10,0));

int dfs(int v, int bit) {
  int res = 0;
  bit |= (1<<(v-1));

  if(bit==((1<<n)-1)) return 1;

  rep(i, g[v].size()) {
    if(g[v][i]==1) {
      if((bit>>(i-1))&1) continue;  // もしもビットが立っていたらcontinue;
      res += dfs(i, bit);
    }
  }

  return res;
}

int main() {
  cin >> n >> m;
  
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    g[a][b] = 1;
    g[b][a] = 1;
  }

  cout << dfs(1, 0) << endl;

  return 0;
}