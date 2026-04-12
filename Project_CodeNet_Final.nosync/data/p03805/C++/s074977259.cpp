#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,m; cin>>n>>m;
    ll ans=0;
    bool graph[10][10]={};
    rep(i,m){
        ll a,b; cin>>a>>b;
        a--; b--;
        graph[a][b]=graph[b][a]=true;
    }
    vector<ll> p(n);
    rep(i,n) p[i]=i;
    do{
        bool ok=true;
        if(p[0]!=0) break;
        rep(i,n-1){
            if(!graph[p[i]][p[i+1]]) ok=false;
        }
        if(ok) ++ans;
    }while(next_permutation(all(p)));
    cout<<ans<<endl;
    return 0;
}