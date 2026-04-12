#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int n, m, ans;
vector<vector<int> > G;
vector<bool> visit;

void dfs(int now){
  visit[now] = true;
  bool check = true;
  for(auto next : G[now]){
    if(!visit[next]) dfs(next), check = false;
  }
  if(check){
    bool ok = true;
    for(int i = 0; i < visit.size(); i++) if(!visit[i]) ok = false;
    if(ok) ans++;
  }
  visit[now] = false;
}

signed main(){
  cin >> n >> m;
  G.resize(n);
  visit.resize(n, false);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    G[a - 1].push_back(b - 1); G[b - 1].push_back(a - 1);
  }
  dfs(0);
  cout << ans << endl;
}
