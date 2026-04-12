#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int mod = 1000000007;
int n;
int a[105];
ll exp(ll a, ll x){
    if (x == 0) return 1ll;
    ll p = exp(a,x/2);
    p = (p*p)%mod;
    if (x & 1){
        p = (p*a)%mod;
    }
    return p;
}
ii solve(int l, int r, int s){
    if (l > r) return ii(1ll,0ll);
    int pos = l;
    for (int i = l; i <= r; i++){
        if (a[i] < a[pos]) pos = i;
    }
    ii L = solve(l,pos-1,a[pos]);
    ii R = solve(pos+1,r,a[pos]);
    ll prod1 = (ll)(L.first)*(R.first)%mod;
    ll prod2 = (ll)(L.first+L.second)*(R.first+R.second)%mod;
    ll ex = exp(2,a[pos]-s);
    ll dp1 = (ex*prod1)%mod;
    ll dp2 = (2*prod2 + (ex-2)*prod1)%mod;
    //printf("%d %d %lld %lld\n",l,r,dp1,dp2);
    return ii(dp1,dp2);
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&a[i]);
    printf("%lld",solve(0,n-1,0).second);
}
