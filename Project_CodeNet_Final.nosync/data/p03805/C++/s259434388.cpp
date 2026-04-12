#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define INF 100100100
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

//v：始点、n：頂点の数、count：通った辺の数
vector<bool> seen;

int dfs(Graph &g, int v, int n, int count){
  if(count == n - 1) return 1;
  int ans = 0;
  seen[v] = true;
  for(auto nv : g[v]){
    if(seen[nv]) continue;
    ans += dfs(g, nv, n, count + 1);
    seen[nv] = false;
  }
  return ans;
}

int main(){
  int n, m;
  cin >> n >> m;
  Graph g(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  seen.assign(n,false);
  int count = 0;
  cout << dfs(g,0,n,count) << endl;

  return 0;
}
