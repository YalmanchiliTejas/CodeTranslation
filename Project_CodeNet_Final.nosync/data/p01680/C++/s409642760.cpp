#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef vector<vector<lli> > Graph;
const lli mod = 1000000007LL;
const lli MAXN = 100005;

lli N, M;
Graph G;
lli vis[MAXN];

void dfs(lli v) {
  vis[v] = true;
  for(lli i = 0; i < G[v].size(); ++i) {
    lli nv = G[v][i];
    if(!vis[nv]) dfs(nv);
  }
}

int main() {
  while(cin >> N >> M && (N|M)) {
    G = Graph(N);
    for(lli i = 0; i < M; ++i) {
      lli a, b; cin >> a >> b;
      --a; --b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    lli cnt = 0, res = 1;
    for(lli i = 0; i < N; ++i) {
      if(!vis[i]) {
        dfs(i);
        ++cnt;
        res = res * 2LL % mod;
      }
    }
    cout << res + (cnt != N) << endl;
  }
  return 0;
}