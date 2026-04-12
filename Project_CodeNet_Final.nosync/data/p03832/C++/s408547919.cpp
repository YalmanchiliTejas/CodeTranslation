#include<iostream>
#include<cstdio>
#define MN 1000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while (ch<'0'||ch>'9')ch=getchar();
    while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
int n,A,B,C,D,f[MN+5],g[MN+5],p[MN+5],inv[MN+5];
int main()
{
    n=read();A=read();B=read();C=read();D=read();
    p[0]=inv[0]=p[1]=inv[1]=f[0]=1;
    for(int i=2;i<=n;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=n;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod;
    for(int i=A;i<=B;++i)
    {
        for(int j=0,w=1;j<=D&&j*i<=n;++j,w=1LL*w*inv[i]%mod) if(j>=C)
            for(int k=0;k+i*j<=n;++k) if(f[k])
                g[k+i*j]=(g[k+i*j]+1LL*f[k]*w%mod*inv[j])%mod;
        for(int j=0;j<=n;++j) f[j]=(f[j]+g[j])%mod,g[j]=0;
    }
    cout<<1LL*p[n]*f[n]%mod;
    return 0;
}
