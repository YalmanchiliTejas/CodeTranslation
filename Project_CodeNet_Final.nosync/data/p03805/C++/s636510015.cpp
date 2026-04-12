#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,m; cin>>n>>m;
    vector<ll> v(n);
    rep(i,n) v[i]=i;
    vector<vector<bool>> path(n,vector<bool>(n,false));
    rep(i,m){
        ll a,b; cin>>a>>b;
        a--; b--;
        path[a][b]=path[b][a]=true;
    }
    ll ans=0;
    do{
        bool ok=true;
        rep(i,n-1){
            if(path[v[i]][v[i+1]]) continue;
            ok=false;
            break;
        }
        if(ok) ans++;
    }while(next_permutation(v.begin()+1,v.end()));
	cout<<ans<<endl;
    return 0;
}