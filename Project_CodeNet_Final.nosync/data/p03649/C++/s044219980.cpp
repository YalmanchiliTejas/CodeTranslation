#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
long long a[51];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	long long ans=0;
	while (a[n]>=n)
	{
		for (int i=n;i>=1;--i)
			if (a[i]>=n)
			{
				long long dec=(a[i]-n)/n+1;
				a[i]-=dec*n;
				for (int j=1;j<=n;++j)
					if (j!=i)
						a[j]+=dec;
				ans+=dec;
			}
		sort(a+1,a+n+1);
	}
	printf("%lld",ans);
	return 0;
}
