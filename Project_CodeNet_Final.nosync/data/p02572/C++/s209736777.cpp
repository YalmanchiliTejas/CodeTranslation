#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
inline long long qr()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while (ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline long long mul(long long x,long long y)
{
	int ans=0;
	while(y)
	{
		if(y&1)
		ans=(ans+x)%mod;
		y>>=1;
		x=(x+x)%mod;
	}
	return ans;
}
int n;
const int maxn=2e5+10;
long long a[maxn];
long long b[maxn];
long long ans;
int main()
{
	n=qr();
	for(register int i=1;i<=n;i++)
	{
		a[i]=qr();
		b[i]=(b[i]+b[i-1]+a[i]);
	}
	for(register int i=1;i<n;i++)
	{
		ans=(ans+mul(a[i],b[n]-b[i])%mod)%mod;
	}
	cout<<ans;
	return 0;
}
