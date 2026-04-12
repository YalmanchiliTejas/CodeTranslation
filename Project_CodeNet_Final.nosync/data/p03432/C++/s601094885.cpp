#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int mod=998244353;
const int gs=3;
int n,m;
int f[205][20005],c[8005][8005],g[20005],h[20005];
long long ft[20005],fir[20005],inv[20005];
long long ksm(long long x,long long n)
{
	long long ans=1;
	while(n)
	{
		if(n&1) ans=ans*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ans;
}
void NTT(int a[],int n,int ty)
{
	for(int i=0;i<n;i++)
	{
		int j=0;
		for(int m=1,k=i;m<n;m<<=1,j=(j<<1)|(k&1),k>>=1);
		if(i<j) swap(a[i],a[j]);
	}
	ft[0]=1;
	for(int m=1;m<n;m<<=1)
	{
		long long w=ksm(gs,(mod-1)/m/2);
		if(ty==-1) w=ksm(w,mod-2);
		for(int i=1;i<m;i++) ft[i]=ft[i-1]*w%mod;
		for(int k=0;k<n;k+=m<<1)
		for(int i=k;i<k+m;i++)
		{
			long long t0=a[i],t1=a[i+m]*ft[i-k]%mod;
			a[i]=(t0+t1)%mod,a[i+m]=(t0-t1+mod)%mod;
		}
	}
	if(ty==-1)
	{
		long long rev=ksm(n,mod-2);
		for(int i=0;i<n;i++) a[i]=a[i]*rev%mod;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+2;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
	fir[0]=fir[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n+2;i++) fir[i]=fir[i-1]*i%mod;
	inv[n+2]=ksm(fir[n+2],mod-2);
	for(int i=n+1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
	int l=1<<(int)ceil(log2(n+n+1));
	for(int i=0;i<=n;i++) f[m][i]=c[n][n-i];
	for(int i=1;i<=n;i++) h[i]=inv[i+2]%mod;
	NTT(h,l,1);
	for(int i=m-1;i>=0;i--) 
	{
		for(int j=0;j<=n;j++) g[j]=f[i+1][j]*fir[n-j+2]%mod;
		for(int j=n+1;j<l;j++) g[j]=0;
		NTT(g,l,1);
		for(int j=0;j<l;j++) g[j]=1ll*g[j]*h[j]%mod;
		NTT(g,l,-1);
		for(int j=0;j<=n;j++) f[i][j]=(g[j]*inv[n-j]%mod+1ll*f[i+1][j]*(c[n-j+1][2]+1)%mod)%mod;
	}
	printf("%lld\n",f[0][n]);
}