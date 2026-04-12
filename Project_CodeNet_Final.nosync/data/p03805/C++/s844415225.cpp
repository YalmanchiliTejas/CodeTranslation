#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<vector<int>> G;

void dfs(vector<bool> &seen,int u,int &res) {
    bool ok = true;
    for(int i = 0;i < seen.size();i++) if(!seen[i] && i != u) ok = false;
    if(ok) {
      res++;
      return;
    }

    seen[u] = true;
    for(auto nu: G[u]) {
      if(!seen[nu]) dfs(seen,nu,res);
    }
    seen[u] = false;
}

int main() {

  int N,M;
  cin >> N >> M;

  G.assign(N,vector<int>());
  vector<bool> seen(N,false);

  for(int i = 0;i < M;i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int res = 0;
  dfs(seen,0,res);

  cout << res << endl;
}