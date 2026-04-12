#include<bits/stdc++.h>
using namespace std;
long long n,x,m;
struct node
{
	long long num,v;
}f[100010];
long long l,r;
long long sum,ans;
bool cnt[100010];
int main()
{
	scanf("%lld%lld%lld",&n,&x,&m);
	f[1].v=x;
	cnt[x]=1;
	f[x].num=1;
	l=1,r=n;
	for(long long i=2;i<=n;i++)
	{
		f[i].v=(f[i-1].v*f[i-1].v)%m;
		if(cnt[f[i].v])
		{
			l=f[f[i].v].num;
			r=i-1;
			break;
		}
		cnt[f[i].v]=1;
		f[f[i].v].num=i;
	}
	for(long long i=1;i<l;i++)
	{
		ans+=f[i].v;
	}
	for(long long i=l;i<=r;i++)
	{
		sum+=f[i].v;
	}
	ans+=((n-l+1)/(r-l+1))*sum;
	long long x=(n-l+1)%(r-l+1);
	for(long long i=l;i<l+x;i++)
	{
		ans+=f[i].v;
	}
	printf("%lld",ans);
	return 0;
}