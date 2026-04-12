#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define mod 998244353
#define maxn 10010
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int quick_pow(int x,int p)
{
    int an=1;
    int po=x;
    while(p)
    {
        if(p&1)  an=1ll*an*po%mod;
        po=1ll*po*po%mod;
        p>>=1;
    }
    return an;
}
int a,b,n;
char s[maxn],t[maxn];
int fac[maxn],inv[maxn];
int f[maxn];
int res;
int C(int x,int y)
{
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1);
    fac[0]=1;
    for(int i=1;i<=n;i++)  fac[i]=1ll*fac[i-1]*i%mod;
    inv[n]=quick_pow(fac[n],mod-2);
    for(int i=n-1;i>=0;i--)  inv[i]=1ll*inv[i+1]*(i+1)%mod;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1'&&t[i]=='1')  a++;
        else if(s[i]=='1')        b++;
    }
    for(int i=0;i<=b;i++)  f[i]=1ll*fac[i]*fac[i]%mod;
    res=1ll*f[b]*fac[a]%mod*fac[a]%mod*C(a+b,a)%mod;
    for(int i=1;i<=a;i++)
    {
        f[0]=0;
        for(int j=1;j<=b;j++)
        {
            f[j]=(1ll*f[j]*i%mod*j%mod+1ll*f[j-1]*j%mod*j%mod)%mod;
        }
        res=(res+1ll*f[b]*fac[a-i]%mod*fac[a-i]%mod*C(a,a-i)%mod*C(a+b,a-i)%mod)%mod;
    }
    printf("%d\n",res);
    return 0;
}