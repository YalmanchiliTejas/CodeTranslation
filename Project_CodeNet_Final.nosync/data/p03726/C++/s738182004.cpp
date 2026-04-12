#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
vector <int> g[N];
ll vis[N];
void dfs(ll v,ll p){
    for (auto u : g[v]){
        if (u==p) continue;
        dfs(u,v);
        if (vis[u]==0 && vis[v]==0){
            vis[u]=1;
            vis[v]=1;
        }
    }
}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=0;i<n-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1);
    for (int i=1;i<=n;i++) if (vis[i]==0) kill("First");
    kill("Second");
}