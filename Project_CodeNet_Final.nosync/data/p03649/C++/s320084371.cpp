#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,u,v;
long long a[100005],sum,ans,tmp;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		if(a[i]>3*n)sum+=a[i]-3*n;
	}
	for(i=1;i<=n;++i)a[i]+=sum;
	ans=sum;
	for(i=1;i<=n;++i)
	if(a[i]>3*n)
	{
		tmp=(a[i]-3*n)/(n+1);
		if(tmp>sum)tmp=sum;
		a[i]-=(n+1)*tmp;
		sum-=tmp;
		if(a[i]>3*n&&sum)
		{
			a[i]-=n+1;
			--sum;
		}
	}
	ans-=sum;
	for(i=1;i<=n;++i)a[i]-=sum;
	for(;;)
	{
		u=1;
		for(i=2;i<=n;++i)
		if(a[i]>a[u])u=i;
		if(a[u]>=n)
		{
			++ans;
			a[u]-=n+1;
			for(i=1;i<=n;++i)++a[i];
		}else break;
	}
	printf("%lld\n",ans);
}