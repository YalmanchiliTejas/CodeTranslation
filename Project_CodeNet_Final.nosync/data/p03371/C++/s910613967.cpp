#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

int main(void){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=INF;
    for(ll i=0;i<=100000;i++){
        ans=min(ans,2*c*i+a*max(ll(0),(x-i))+b*max(ll(0),(y-i)));
    }
    cout<<ans<<endl;
}