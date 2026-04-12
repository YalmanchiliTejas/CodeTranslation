#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e7;
const int mod=998244353;
long long ans=0;
int n;
int fir[maxn+5],inv[maxn+5],mu[maxn+5];
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
long long C(int n,int m)
{
	return 1ll*fir[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	scanf("%d",&n);
	fir[0]=1;
	for(int i=1;i<=n;i++) fir[i]=1ll*fir[i-1]*i%mod;
	inv[n]=ksm(fir[n],mod-2);
	for(int i=n-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	mu[0]=1;
	for(int i=1;i<=n;i++) mu[i]=mu[i-1]*2%mod;
	for(int i=n/2+1;i<=n;i++) ans=(ans+C(n,i)*mu[n-i]%mod)%mod;
	ans=(ksm(3,n)-ans*2%mod)%mod;
	ans=(ans%mod+mod)%mod;
	printf("%lld\n",ans);
}