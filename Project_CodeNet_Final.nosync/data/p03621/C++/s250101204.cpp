#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e4;
const int mod=998244353;
int n,m,len,ans;
char S1[maxn+8],S2[maxn+8];
int fac[maxn+8],fact[maxn+8],f[maxn+8][maxn+8];

int read()
{
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}

int C(int n,int m){return 1ll*fac[n]*fact[m]%mod*fact[n-m]%mod;}
int power(int a,int k)
{
    int sum=1;
    for (;k;k>>=1,a=1ll*a*a%mod)
	if (k&1)
	    sum=1ll*sum*a%mod;
    return sum;
}

int main()
{
    scanf("%s",S1+1);
    scanf("%s",S2+1);
    len=strlen(S1+1);
    fac[0]=fact[0]=1;
    for (int i=1;i<=len;i++) fac[i]=1ll*fac[i-1]*i%mod;
    fact[len]=power(fac[len],mod-2);
    for (int i=len-1;i;i--) fact[i]=1ll*fact[i+1]*(i+1)%mod;
    for (int i=1;i<=len;i++) {if (S1[i]==S2[i]&&S1[i]=='1') n++;if (S1[i]=='1'&&S2[i]=='0') m++;}
    f[0][0]=1;//for (int i=1;i<=m;i++) f[0][i]=1ll*f[0][i-1]*(m-i+1)%mod*(m-i+1)%mod;
    for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++)
	    {
		if (i) f[i][j]=(f[i][j]+1ll*f[i-1][j]*(n-i+1)%mod*(m-j)%mod)%mod;
		if (j) f[i][j]=(f[i][j]+1ll*f[i][j-1]*(m-j+1)%mod*(m-j+1)%mod)%mod;
	    }
    for (int i=0;i<=n;i++)
	{
	    //printf("%d\n",f[i][m]);
	    ans=(ans+1ll*f[i][m]*fac[n-i]%mod*fac[n-i]%mod*C(n+m,n-i)%mod)%mod;
	}
    printf("%d\n",ans);
    return 0;
}
