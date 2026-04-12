#include<cstdio>
#include<algorithm>
using namespace std;
long long g[3001][3001];
long long n;
long long mod;
long long quickpow(long long a,long long b,long long modd)
{
	if(a==0&&b==0) return 0LL;
	if(b==0) return 1LL;
	else if(b==1) return a%modd;
	else if(b%2==0) return quickpow(a*a%modd,b/2,modd)%modd;
	else return quickpow(a*a%modd,b/2,modd)*a%modd;
}
long long f[3001];
long long fac[3050];
long long Cnm(long long n,long long m)
{
	if(n<m||n<0||m<0) return 0LL;
	if(m==0||n==m) return 1LL;
	long long sex=(fac[n-m]*fac[m])%mod;
	long long sex1=(quickpow(sex,mod-2,mod))%mod;
	return sex1*fac[n]%mod;
}
long long ans;
int main()
{
	scanf("%lld %lld",&n,&mod);
	fac[0]=1;
	fac[1]=1;
	for(long long i=2;i<=3000;i++) fac[i]=(fac[i-1]*i)%mod; 
	for(int i=0;i<=n;i++)
	{
		g[i][0]=1LL;
		for(long long j=1;j<=i;j++)
		{
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1LL)%mod)%mod;
		}
	}
	for(int i=0;i<=n;i++)
	{
		long long sex=quickpow(2,(n-i),mod);
		long long penis=1;
		for(int j=0;j<=i;j++)
		{
			f[i]=((f[i]+g[i][j]*penis%mod)%mod+mod)%mod;
			penis*=sex;
			penis%=mod;
		}
		long long x=quickpow(2,n-i,mod-1);
		x=quickpow(2,x,mod);
		f[i]=(f[i]*x)%mod;
	}
	for(int i=0;i<=n;i++)
	{
		if(i%2!=0) ans-=Cnm(n,(long long)i)*f[i]%mod;
		else ans+=Cnm(n,(long long)i)*f[i]%mod;
		ans=(ans+mod)%mod;
	}
	printf("%lld",(ans+mod)%mod);
	return 0;
}