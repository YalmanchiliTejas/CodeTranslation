#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,m; cin>>n>>m;
    bool g[10][10]={};
    rep(i,m){
        ll a,b; cin>>a>>b;
        --a; --b;
        g[a][b]=g[b][a]=true;
    }
    ll ans=0;
    vector<ll> p(n);
    rep(i,n) p[i]=i;
    do{
        if(p[0]!=0) break;
        bool ok=true;
        rep(i,n-1){
            if(!g[p[i]][p[i+1]]) ok=false;
        }
        if(ok) ans++;
    }while(next_permutation(all(p)));
    cout<<ans<<endl;
    return 0;
}