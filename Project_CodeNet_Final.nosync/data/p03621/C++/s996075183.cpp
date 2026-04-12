#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 10000
#define mod 998244353
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char A[MN+5],B[MN+5];
int f[MN+5][MN+5],p[MN+5],g[MN+5],inv[MN+5],n,num1,num2,ans;
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
inline int C(int n,int m){return 1LL*p[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
    scanf("%s%s",A+1,B+1);n=strlen(A+1);p[0]=inv[0]=p[1]=inv[1]=g[0]=1;
    for(int i=2;i<=n;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=n;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod,g[i]=1LL*(i-1)*(g[i-1]+g[i-2])%mod;
    for(int i=1;i<=n;++i) if(A[i]=='1'&&B[i]=='1') ++num2; else if(A[i]=='1') ++num1;
    f[num1][0]=1;
    for(int i=num1;~i;--i) for(int j=0;j<=num2;++j) if(f[i][j])
    {
        if(i) R(f[i-1][j],1LL*f[i][j]*i*i%mod);
        if(i) R(f[i][j+1],1LL*f[i][j]*i%mod);
        R(f[i][j+1],f[i][j]);
    }
    for(int j=0;j<=num2;++j) ans=(ans+1LL*C(num2+num1,num2-j)*C(num2,j)%mod*f[0][j]%mod*p[j]%mod*g[num2-j]%mod*p[num2-j])%mod;
    printf("%d",ans);
    return 0;
}
