#include <bits/stdc++.h>
using namespace std;
int n;
#define modp 998244353
#define Maxn 10000007
int power(int a,int b)
{
    int res=1,now=a,left=b;
    while (left>0)
    {
        if (left%2==1) res=(1LL*res*now)%modp;
        left/=2;
        now=(1LL*now*now)%modp;
    }
    return res;
}
int bin[Maxn],pre[Maxn],inv[Maxn];
int calc(int x,int y)
{
    int res=(1LL*pre[x]*inv[y])%modp;
    return (1LL*res*inv[x-y])%modp;
}
int main()
{
    scanf("%d",&n);
    int ans=0;
    bin[0]=1;
    for (int i=1;i<=n;i++)
        bin[i]=(2LL*bin[i-1])%modp;
    pre[0]=1;
    for (int i=1;i<=n;i++)
        pre[i]=(1LL*pre[i-1]*i)%modp;
    inv[n]=power(pre[n],modp-2);
    for (int i=n;i;i--)
        inv[i-1]=(1LL*inv[i]*i)%modp;
    for (int i=n/2+1;i<=n;i++)
        ans=(ans+1LL*calc(n,i)*bin[n-i])%modp;
    ans=(2LL*ans)%modp;
    ans=(power(3,n)+modp-ans)%modp;
    printf("%d\n",ans);
    return 0;
}
