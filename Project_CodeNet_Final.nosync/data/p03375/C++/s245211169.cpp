#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200102
int n,p,f[N],inv[N],finv[N],bin[N],bn[N],s[3003][3003];
inline int C(int nn,int mm)
{
    if(nn<mm)return 0;
    return 1ll*f[nn]*finv[mm]%p*finv[nn-mm]%p;
}
int main()
{
    scanf("%d%d",&n,&p);
    f[0]=finv[0]=f[1]=finv[1]=inv[1]=1;
    for(int i=2;i<=20000;i++)
    {
        inv[i]=1ll*(p-p/i)*inv[p%i]%p;
        f[i]=1ll*f[i-1]*i%p;finv[i]=1ll*finv[i-1]*inv[i]%p;
    }
    bin[0]=1;bn[0]=2;
    for(int i=1;i<=n;i++)bin[i]=1ll*bin[i-1]*2%p,bn[i]=1ll*bn[i-1]*bn[i-1]%p;
    s[0][0]=1;
    for(int i=1;i<=n+1;i++)for(int j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j%p)%p;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        int te=0,w=1;
        for(int j=0;j<=i;j++)
        {
            te=(te+1ll*s[i+1][j+1]*bn[n-i]%p*w%p)%p;
            w=1ll*w*bin[n-i]%p;
        }
        te=1ll*te*C(n,i)%p;
        if(i&1)ans=(ans-te+p)%p;
        else ans=(ans+te)%p;
    }
    printf("%d\n",ans);
}
