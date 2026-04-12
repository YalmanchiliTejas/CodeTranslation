#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
const double pi=acos(-1.0);
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
ll a[N];
const ll mod=1e9+7;
ll sum[N];
signed main(){
    int n;
    si(n);
    for (int i = 1; i <=n ; ++i) {
        sl(a[i]);
    }
    for(int i=n;i>=1;i--){
        sum[i]=sum[i+1]+a[i];
    }
    ll ans=0;
    for(int i=1;i<n;i++){
        ans=(ans%mod+(a[i]%mod)*(sum[i+1]%mod)%mod)%mod;
    }
    pl(ans);
    return 0;
}