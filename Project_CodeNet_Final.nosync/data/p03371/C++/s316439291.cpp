#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c;cin>>a>>b>>c;
    ll x,y;cin>>x>>y;
    ll ans = 1e15;
    for(ll abp=0;abp<=max(x,y)*100;abp+=2){
        ll rema = x - abp/2;
        rema=max(0ll,rema);
        ll remb = y - abp/2;
        remb=max(0ll,remb);
        ll cost = rema*a + remb*b + abp*c;
        ans=min(ans,cost);
    }
    cout<<ans;
}
