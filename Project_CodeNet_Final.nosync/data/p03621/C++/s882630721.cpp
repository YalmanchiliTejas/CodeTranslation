#include <bits/stdc++.h>
using namespace std;

#define MAXN 50010
#define mod 998244353

char a[MAXN],b[MAXN];
int n,m,l,fac[MAXN],inv[MAXN],val[MAXN],res;

int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=(long long)res*a%mod;
		a=(long long)a*a%mod;
		b>>=1; 
	}
	return res;
}

int c(int n,int m)
{
	return (long long)fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int calc(int n,int m,int k)
{
	return (long long)c(m,k)*fac[k]%mod*fac[m-k]%mod*fac[m-k]%mod*c(n+m,m-k)%mod;
}

int main()
{
	scanf("%s%s",a+1,b+1);
	l=strlen(a+1);
	for(int i=1;i<=l;++i)
	{
		n+=a[i]=='1'&&b[i]=='0';
		m+=a[i]=='1'&&b[i]=='1';
	}
	fac[0]=1;
	for(int i=1;i<=50000;++i)fac[i]=(long long)fac[i-1]*i%mod;
	inv[50000]=qpow(fac[50000],mod-2);
	for(int i=49999;i>=0;--i)inv[i]=(long long)inv[i+1]*(i+1)%mod;
	for(int i=0;i<=n;++i)val[i]=(long long)c(n,i)*qpow(i,n)%mod;
	for(int k=0;k<=m;++k)
	{
		long long tmp=0;
		for(int i=0;i<=n;++i)
		{
			if(n-i&1)tmp-=val[i];else tmp+=val[i];
			tmp%=mod;
		}
		tmp+=mod;
		tmp%=mod;
		res=(res+(long long)fac[n]*tmp%mod*calc(n,m,k)%mod)%mod;
		for(int i=0;i<=n;++i)
		{
			val[i]=(long long)val[i]*i%mod;
		}
	}
	printf("%d\n",res);
}