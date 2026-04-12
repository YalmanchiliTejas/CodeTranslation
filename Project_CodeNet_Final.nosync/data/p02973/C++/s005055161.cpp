#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin>>n;
    vector<ll> b;
    ll ans=0;
    for(ll i=0; i<n; i++){
        ll a;cin>>a;
        auto itr = upper_bound(b.begin(),b.end(),-a);
        if(itr==b.end()){ans++;b.push_back(-a);}
        else *itr=-a;
    }
    cout<<ans<<endl;
    return 0;
}