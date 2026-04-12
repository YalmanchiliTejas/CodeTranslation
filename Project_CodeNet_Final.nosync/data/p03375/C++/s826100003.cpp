#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5010, inf=1e9;
int n, m, mod;
int fac[maxn], inv[maxn], s[maxn][maxn];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;
}

inline int power(int a, int b, int mod)
{
	int ans=1;
	for(;b;b>>=1, a=1ll*a*a%mod)
	if(b&1) ans=1ll*ans*a%mod;
	return ans;
}

inline int C(int n, int m){return (n<m)?0:1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;}

int main()
{
	read(n); read(mod);
	fac[0]=1; for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=power(fac[n], mod-2, mod); for(int i=n;i;i--) inv[i-1]=1ll*inv[i]*i%mod;
	s[0][0]=1;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=i;j++) 
		s[i][j]=(s[i-1][j-1]+1ll*s[i-1][j]*j)%mod;
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int sum=0, mi=1;
		for(int j=0;j<=i;j++)
		{
			sum=(sum+1ll*mi*s[i+1][j+1])%mod;
			mi=1ll*mi*power(2, n-i, mod)%mod;
		}
		sum=1ll*sum*C(n, i)%mod*power(2, power(2, n-i, mod-1), mod)%mod;
		if(i&1) ans=(ans-sum+mod)%mod;
		else ans=(ans+sum)%mod;
	}
	printf("%d\n", ans);
}