#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define INF 1e9
#define all(v) v.begin(), v.end()
typedef long long ll;
using Graph = vector<vector<int> >;

Graph G;
vector<bool> seen;

int dfs(int v, int &res){
  seen[v] = true;
  bool end = true;
  rep(i, seen.size()) if(!seen[i]) end = false;

  if(end){
    ++res;
    seen[v] = false;
    return 0;
  }

  for(auto nv : G[v]){
    if(seen[nv]) continue;
    dfs(nv, res);
  }

  seen[v] = false;
}

int main(){
  int n, m; cin >> n >> m;
  G.assign(n, vector<int>());
  rep(i, m){
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  seen.assign(n, false);
  int res = 0;
  dfs(0, res);

  cout << res << endl;

  return 0;
}
