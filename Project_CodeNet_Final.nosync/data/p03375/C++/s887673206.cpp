#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int N=3000;
LL n,mo,fac[N+10],inv[N+10],pw[N+10],f[N+10][N+10];
LL mul(LL x,LL y,LL mod=mo) {
    x%=mod;
    LL z=1;
    while (y) {
        if (y&1) z=z*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return z;
}
void prework() {
    fac[0]=1;
    for (int i=1;i<=N;i++) fac[i]=fac[i-1]*i%mo;
    inv[N]=mul(fac[N],mo-2);
    for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mo;
}
LL C(LL x,LL y) {
    if (y>x||y<0) return 0;
    return fac[x]*inv[y]%mo*inv[x-y]%mo;
}
void work() {
    LL ans=0;
    for (int i=0;i<=n;i++) pw[i]=mul(2,mul(2,i,mo-1));
    f[0][0]=1;
    for (int i=1;i<=n+1;i++) {
        f[i][0]=0;
        for (int j=1;j<=i;j++)
            f[i][j]=(f[i-1][j-1]+f[i-1][j]*j)%mo;
    }
    for (int i=0;i<=n;i++) {
        LL now=mul(mo-1,i)*C(n,i)%mo*pw[n-i]%mo;
        LL nowx=mul(2,n-i),sumx=0;
        for (LL j=0,sx=1;j<=i;j++,sx=sx*nowx%mo)
            sumx=(sumx+sx*f[i+1][j+1])%mo;
        now=now*sumx%mo;
        ans=(ans+now)%mo;
    }
    ans=(ans%mo+mo)%mo;
    printf("%lld\n",ans);
}
int main() {
    scanf("%lld%lld",&n,&mo);
    prework();
    work();
    return 0;
}
