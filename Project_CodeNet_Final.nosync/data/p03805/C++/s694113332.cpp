#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

vector<vector<ll>>g;
ll n;
void dfs(ll v,vector<bool>&c,ll &ans){
    bool flg=true;
    for (int i = 0; i < n; ++i) {
        if(c[i]&&i!=v)flg=false;
    }
    if(flg){
        ans++;
        return;
    }
    c[v]=false;
    for(auto u:g[v]){
        if(!c[u])continue;
        dfs(u,c,ans);
    }
    c[v]=true;
};

int main(){
    ll m;cin >>n>>m;
    g.assign(n,vector<ll>());
    for (int i = 0; i < m; ++i) {
        ll a,b;cin >>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans=0;
    vector<bool>c(n,true);
    dfs(0,c,ans);
    cout <<ans <<endl;
    return 0;
}