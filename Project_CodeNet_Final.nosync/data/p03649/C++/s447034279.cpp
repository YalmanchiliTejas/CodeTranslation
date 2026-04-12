#include<cstdio>
#include<cassert>
#include<algorithm>
using namespace std;
long long n,a[100];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	long long cur=n,ans=0;
	while(a[cur]>=n)
	{
		long long x=(a[cur]-n+1)/n;
		a[cur]-=x*n;
		if(a[cur]>=n)a[cur]-=n,x++;
		for(int i=1;i<=n;i++)
			if(i!=cur)a[i]+=x;
		ans+=x;
		sort(a+1,a+1+n);
	}
	printf("%lld\n",ans);
	return 0;
}
