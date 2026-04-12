#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=3111;
int mod;
int qpow(int x,int y,const int&mod=::mod)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=(LL)ret*x%mod;
		x=(LL)x*x%mod;
		y>>=1;
	}
	return ret;
}
inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}

int s[maxn][maxn],n,fac[maxn],invf[maxn],inv[maxn];
int main()
{
	scanf("%d%d",&n,&mod);
	
	fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=(LL)i*fac[i-1]%mod;
	invf[maxn-1]=qpow(fac[maxn-1],mod-2);for(int i=maxn-1;i>=1;i--)invf[i-1]=(LL)i*invf[i]%mod;
	for(int i=1;i<maxn;i++)inv[i]=(LL)invf[i]*fac[i-1]%mod;
	s[0][0]=1;
	for(int i=1;i<=n+1;i++)for(int j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+(LL)j*s[i-1][j])%mod;
	
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int sum=0,val=qpow(2,n-i),p=1;
		for(int k=0;k<=i;k++)
		{
			sum=(sum+(LL)s[i+1][k+1]*p)%mod;
			p=(LL)p*val%mod;
		}
		sum=(LL)sum*fac[n]%mod*invf[i]%mod*invf[n-i]%mod*qpow(2,qpow(2,n-i,mod-1))%mod;
		if(i&1)add(ans,mod-sum);
		else add(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}