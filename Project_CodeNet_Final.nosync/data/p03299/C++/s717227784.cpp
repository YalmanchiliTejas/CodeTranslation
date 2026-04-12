#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL mo=1e9+7;
const int N=1000;
int n,ok[N+10];
LL h[N+10],h2[N+1],f[N+10][N+10];
LL mul(LL x,LL y) {
    LL z=1;
    while (y) {
        if (y&1) z=z*x%mo;
        y>>=1;
        x=x*x%mo;
    }
    return z;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%lld",&h[i]);
        h2[i]=h[i];
    }
    sort(h2+1,h2+n+1);
    h2[0]=1;
    for (int i=n;i>=0;i--)
        if (i==n||h2[i]!=h2[i+1]) ok[i]=1;
    h2[n+1]=1e9;
    for (int i=0;i<=n;i++) {
        if (h2[i]>h[1]) break;
        if (!ok[i]) continue;
        if (h2[i+1]<=h[1]) f[1][i]=(mul(2,h[1]-h2[i])-mul(2,h[1]-h2[i+1]))*2%mo;
        else f[1][i]=mul(2,h[1]-h2[i])*2%mo;
    }
    for (int i=1;i<n;i++)
        for (int j=0;j<=n;j++) {
            if (f[i][j]==0) continue;
            if (h[i]<h[i+1]) {
                if (h2[j]==h[i])
                    for (int j2=j;j2<=n;j2++) {
                        if (!ok[j2]||h2[j2]>h[i+1]) continue;
                        LL now;
                        if (h2[j2+1]<=h[i+1])
                            now=f[i][j]*(mul(2,h[i+1]-h2[j2])-mul(2,h[i+1]-h2[j2+1]))%mo;
                        else now=f[i][j]*mul(2,h[i+1]-h2[j2])%mo;
                        f[i+1][j2]=(f[i+1][j2]+now*2)%mo;
                    }
                else f[i+1][j]=(f[i+1][j]+f[i][j]*mul(2,h[i+1]-h[i]))%mo;
                continue;
            }
            if (h2[j]>=h[i+1]) {
                int num=0;
                for (int j=n;j>=0;j--)
                    if (h2[j]==h[i+1]) {
                        num=j;
                        break;
                    }
                f[i+1][num]=(f[i+1][num]+f[i][j]*2)%mo;
            }
            else f[i+1][j]=(f[i+1][j]+f[i][j])%mo;
        }
    LL ans=0;
    for (int i=0;i<=n;i++)
        ans=(ans+f[n][i])%mo;
    ans=(ans%mo+mo)%mo;
    printf("%lld\n",ans);
    return 0;
}
