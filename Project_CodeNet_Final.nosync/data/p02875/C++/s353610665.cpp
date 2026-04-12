#include<iostream>
#include<cstdio>
const int N=1e7+5;
typedef long long ll;
const ll mod=998244353;
ll qpow(ll x,ll y) {
    ll res=1;
    for(;y;y>>=1,x=x*x%mod) if(y&1) res=res*x%mod;
    return res;
}
ll p[N],inv[N];
ll C(int n,int m) {
    if(n<m) return 0;
    return p[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
    int n;
    p[0]=1;
    for(int i=1;i<N;i++) p[i]=p[i-1]*i%mod;
    inv[N-1]=qpow(p[N-1],mod-2);
    for(int i=N-2;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;
    scanf("%d",&n);
    ll ans=qpow(3,n);
    for(int i=n/2+1;i<=n;i++) {
        ll c=qpow(2,n-i+1);
        ans=(ans-c*C(n,i)%mod+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
