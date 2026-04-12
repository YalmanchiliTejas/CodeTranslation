#include<bits/stdc++.h>
#define LL long long 
#define mod 1000000007
using namespace std;

int n;
LL sol;
LL a[200006];
LL sum[2000006];

inline int qr()
{
	char a=0;int x=0,w=1;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<1)+(x<<3)+(a^48);a=getchar();}
	return x*w;
}

inline LL qrl()
{
	char a=0;LL x=0,w=1;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<1)+(x<<3)+(a^48);a=getchar();}
	return x*w;
}

inline LL mul(LL x,LL y)
{
	LL ans=0;
	while(y)
	{
		if(y&1)
			ans=(ans+x)%mod;
		y=y>>1;
		x=(x<<1)%mod;
	}
	return ans;
}

int main()
{
	n=qr();
	for(register int i=1;i<=n;i++)
	{
		a[i]=qr();
		sum[i]=sum[i-1]+a[i];
	}
	for(register int i=1;i<n;i++)
		sol=(sol+mul(a[i],sum[n]-sum[i]))%mod;
	printf("%lld\n",sol);
	return 0;
}