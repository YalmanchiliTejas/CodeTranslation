#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF=1001001001001001001;
// Combination Table
vector<ll> g[8];

ll ans=0;
int dfs(int t, vector<bool>vis){
//  cout<<t<<endl;
vis[t]=true;
  bool check=true;
  rep(i,vis.size()){
    if (vis[i]==false)check=false;
  }
  if (check==true){
    ans++;return 0;
  }
  for(int to:g[t]){
    if (vis[to]==true)continue;
  //
    dfs(to,vis);
  }
  return 0;
}

int main() {
  ll n,m;
  cin>>n>>m;
  rep(i,m){
    ll a1,b1;
    cin>>a1>>b1;
    a1--;b1--;
    g[a1].push_back(b1);
    g[b1].push_back(a1);
  }
  vector<bool> V(n);
//  V[0]=true;
  dfs(0,V);
  cout<<ans;

}
