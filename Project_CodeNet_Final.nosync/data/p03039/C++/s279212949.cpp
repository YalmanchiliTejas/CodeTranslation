#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n,k;
const LL mof=1e9+7;
LL p=mof;
const LL maxn=200007;
inline LL pow_mod(LL a,LL k,LL mo)
{
    LL ans=1;
    while(k)
    {
        if(k%2) ans=ans*a%mo;
        a=a*a%mo;
        k>>=1;
    }
    return ans%mo;
}
LL jc[maxn+7];
inline LL inv(LL x)
{
    return pow_mod(x,mof-2,mof);
}
LL Inv[maxn+7];
LL C(LL N,LL k)
{
    if(k>N||k<0)return 0;
    if(k==0||k==N)return 1;
    LL ans=1;
    ans=ans*jc[N]*Inv[k]%mof*Inv[N-k]%mof;
    return ans;
}
void init()
{
    jc[1]=jc[0]=1;
    for(LL i=2; i<=maxn; ++i) jc[i]=jc[i-1]*i%mof;
    for(int i=0; i<=maxn; ++i) Inv[i]=inv(jc[i]);
}
int main()
{
    init();
    LL n,m,k;
    cin>>n>>m>>k;
    LL ans = 0;
    LL cnt = 0;
    for(LL d=1;d<=m;++d)
        cnt += d * (m-d) % mof;
    ans += cnt * n % mof * n % mof * C(n*m-2,k-2) % mof;
    cnt = 0;
    for(LL d=1;d<=n;++d)
        cnt += d * (n-d) % mof;
    ans += cnt * m % mof * m % mof * C(n*m-2,k-2) % mof;
    ans %= mof;
    cout<<ans<<endl;
}