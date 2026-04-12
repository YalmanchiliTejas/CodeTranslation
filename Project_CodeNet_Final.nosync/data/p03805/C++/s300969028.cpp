#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 10;

vector < bool > used(MAXN, false);
vector < vector < ll > > adj(MAXN, vector < ll > ());

ll ans = 0, n, m;

void bfs(ll u){
  used[u] = true;
  for(auto to : adj[u]){
    if(!used[to]){
      bfs(to);
      used[to] = false;
    }
  }
  bool ok = true;
  for(int i = 1; i <= n; i++){
    if(!used[i]) ok = false;
  }
  if(ok) ans++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++){
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bfs(1);

  cout << ans << '\n';
}
