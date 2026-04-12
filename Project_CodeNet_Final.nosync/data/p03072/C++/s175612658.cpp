#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll MOD = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n; cin>>n;
    vector<ll> h(n);
    rep(i,n) cin>>h[i];
    ll ans=0,tmp=0;
    rep(i,n){
        if(tmp<=h[i]){
            tmp=h[i];
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}