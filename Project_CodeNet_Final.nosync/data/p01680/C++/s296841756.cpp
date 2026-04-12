#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const lli mod = 1000000007LL;

int N, M;
vector<vector<int> > G;
vector<int> vis;

void dfs(int v) {
  vis[v] = true;
  for(int i = 0; i < G[v].size(); ++i) {
    if(vis[G[v][i]]) continue;
    dfs(G[v][i]);
  }
}

lli mod_pow(lli x, lli n) {
  if(n == 0) return 1;
  lli y = mod_pow(x, n/2);
  if(n & 1) return y * y % mod * x % mod;
  else return y * y % mod;
}

int main() {
  while(cin >> N >> M && (N|M)) {
    G = vector<vector<int> >(N);
    for(int i = 0; i < M; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    lli n_cmp = 0;
    vis = vector<int>(N);
    for(int i = 0; i < N; ++i) {
      if(vis[i]) continue;
      ++n_cmp;
      dfs(i);
    }
    cout << (mod_pow(2LL, n_cmp) + (n_cmp != N)) % mod << endl;
  }
  return 0;
}