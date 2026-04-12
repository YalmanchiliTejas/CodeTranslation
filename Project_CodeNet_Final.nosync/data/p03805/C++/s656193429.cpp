#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)


ll dfs(vector<vector<ll>> g, ll vt, vector<bool> used, vector<ll> v){
  v.push_back(vt);
  if(v.size()==g.size()){
    return 1;
  }
  ll ans=0;
  FOR(j,0,g.size()){
    if(g[vt][j]==1 && !used[j]){
      used[vt]=true;
      ans+=dfs(g, j, used, v);
      used[vt]=false;
    }
  }
  return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> g(n,vector<ll>(n));
    FOR(i,0,m){
      ll a,b;
      cin>>a>>b;
      a--;b--;
      g[a][b] = g[b][a] = 1;
    }
    vector<ll> v;
    vector<bool> used(n, false);
    cout<<dfs(g,0,used,v)<<endl;
}
