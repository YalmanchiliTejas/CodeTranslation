#include <bits/stdc++.h>
using namespace std;
int n,mod,fac[3005],inv[3005];
int f[3005][3005],c[3005][3005];
inline int qpow(int a,int b,int mod)
{int res=1,tp=a;
while (b)
{if (b&1) res=1ll*res*tp%mod;
tp=1ll*tp*tp%mod;b>>=1;
}
return res;
}
int main (){
	int i,j,k,ans=0;
	fac[0]=1;
	scanf ("%d%d",&n,&mod);
	for (i=1;i<=n;i++)
	{fac[i]=1ll*fac[i-1]*i%mod;
	inv[i]=qpow(fac[i],mod-2,mod);
	}
	for (i=0;i<=n;i++)
	{c[i][0]=c[i][i]=1;
	for (j=1;j<i;j++)
	{c[i][j]=c[i-1][j-1]+c[i-1][j];
	if (c[i][j]>=mod) c[i][j]-=mod;
	}
	}
	f[0][0]=1;
	for (i=1;i<=n;i++)
	{f[i][0]=1;
	for (j=1;j<=i;j++)
	{f[i][j]=1ll*f[i-1][j]*(j+1)%mod;
	f[i][j]=(f[i][j]+f[i-1][j-1]>=mod?f[i][j]+f[i-1][j-1]-mod:f[i][j]+f[i-1][j-1]);
	}
	}
	for (i=0;i<=n;i++)
	{int wys=qpow(2,n-i,mod),now=1,res=0;
	int rm=qpow(2,qpow(2,n-i,mod-1),mod);
	for (j=0;j<=i;j++)
	{res+=1ll*f[i][j]*now%mod;
	now=1ll*now*wys%mod;
	if (res>=mod) res-=mod;
	}
	res=1ll*res*rm%mod;
	res=1ll*res*c[n][i]%mod;
	if (i&1) {ans-=res;}
	else {ans+=res;}
	if (ans<0) ans+=mod;
	if (ans>=mod) ans-=mod;
	}
	printf ("%d\n",ans);
	return 0;
}