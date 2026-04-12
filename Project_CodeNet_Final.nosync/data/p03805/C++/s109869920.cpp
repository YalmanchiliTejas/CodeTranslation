#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
/*

*/
ll ans = 0, N, M;
vector<vector<ll>> G;

void dfs(ll now, vector<ll> seen){
  seen[now] = 1;
  for(ll i=1; i<=N; i++){
    if (seen[i] == 0)
      break;
    if (i == N){
      ans++;
      return;
    }
  }
  for(auto v: G[now]){
    if (seen[v])
      continue;
    dfs(v, seen);
  }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >>N >>M;
    G.assign(N+1, vector<ll>(0,0));
    vector<ll> seen(N+1,0);
    rep(i,M){
    	ll a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, seen);
    cout<<ans<<endl;
}