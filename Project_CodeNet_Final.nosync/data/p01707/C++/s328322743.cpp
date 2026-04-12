#include <cstdio>

#include <cmath>

#include <cstring>

#include <iostream>

#include <algorithm>

#include <queue>

#include <vector>

#include <map>



using namespace std;



typedef long long LL;


LL n,d,x,ans;
LL dp[2005][2005];
LL c[2005];
int l,r;
LL ny[2005];
const int mod=1e9+7;
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,LL w)
{
	for (int i=x;i<=n+1;i+=lowbit(i)) 
		c[i]+=w,c[i]%=mod;
}
LL powmod(LL a,LL b,LL c)
{
	LL ans=1;
	while (b)
	{
		if (b&1) ans=ans*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ans;
}
LL cc(LL n,LL m)
{
	if (n<m) return 0;
	LL ans=1;
	for (int i=1;i<=m;++i)
	{
		LL a=n-i+1;
		LL b=i;
		ans=ans*a%mod;
		ans=ans*ny[b]%mod;
	}
	return ans;
}
LL work(LL n,LL m)
{
	if (m==0) return 1;
	return work(n/mod,m/mod)*cc(n%mod,m%mod)%mod;	
}
LL sum(int x)
{
	LL ans=0;
	for (int i=x;i>0;i-=lowbit(i))
		ans+=c[i],ans%=mod;
	return ans;
}

int main()

{
	for (int i=1;i<=2002;++i) ny[i]=powmod(i,mod-2,mod);
	while (scanf("%lld%lld%lld",&n,&d,&x)!=EOF)
	{
		if (n+d+x==0) break;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		memset(c,0,sizeof(c));
		add(1,1);
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=n;++j)
			{
				l=j-x+1;r=j-1;
				l=max(l,0);
				l++;r++;
				dp[i][j]=sum(r)-sum(l-1);
				dp[i][j]%=mod;
				dp[i][j]=(dp[i][j]+mod)%mod;
			}
			memset(c,0,sizeof(c));
			for (int j=1;j<=n;++j) add(j+1,dp[i][j]);
		}			
		ans=0;
		for (int i=1;i<=n;++i) ans+=work(d,i)*dp[i][n]%mod,ans%=mod;
		printf("%lld\n",ans);
	}

    return 0;

}