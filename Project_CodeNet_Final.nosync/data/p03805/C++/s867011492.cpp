#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
int ans = 0;
int n, m;
bool vis[10];
vi adj[10];
void dfs(int u, int cnt){
  if(cnt == n)ans++;
  vis[u] = true;
  for(auto v : adj[u]){
    if(!vis[v])
      dfs(v, cnt + 1);
  }
  vis[u] = false;
}
int main(){
  cin >> n >> m;
  while(m--){
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0,1);
  cout << ans << '\n';
  return 0;
}
