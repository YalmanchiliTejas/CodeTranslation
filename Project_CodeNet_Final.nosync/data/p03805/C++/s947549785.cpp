#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

int main(){
    vector<ll> p;
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> g(n,vector<ll>(n,0));
    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        g[a][b]=1;
        g[b][a]=1;
    }
    rep(i,n-1)p.push_back(i+1);
    ll ans=0;
    do{
        bool f=true;
        ll prev=0;
        rep(i,n-1){
            if(g[prev][p[i]]==0){
                f=false;
                break;
            }
            prev=p[i];
        }
        if(f)ans++;
    }while(next_permutation(p.begin(), p.end()));
    cout<<ans<<endl;
}
