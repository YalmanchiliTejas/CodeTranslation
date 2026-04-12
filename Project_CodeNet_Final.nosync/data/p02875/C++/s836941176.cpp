#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10000010,mod=998244353;

ll fac[maxn],inv[maxn],ans;
ll fpm(ll a,ll b){
    ll ret=1ll;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)ret=ret*a%mod;
    return ret;
}
ll C(ll n,ll m){
    if(n<0||m<0||n-m<0)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int n;

void solve(){
    scanf("%d",&n);
    fac[0]=1;ans=fpm(3,n);
    for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
    inv[n]=fpm(fac[n],mod-2);
    for(int i=n;i;--i)inv[i-1]=inv[i]*i%mod;
    for(int i=(n>>1)+1;i<=n;++i)
        (ans-=C(n,i)*fpm(2,n-i+1)%mod)%=mod,(ans+=mod)%=mod;
    printf("%lld\n",ans);
}
int main(){
    solve();

    return 0;
}