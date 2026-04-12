#include <iostream>
using namespace std;
long long arr[55];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%lld",&arr[i]);
	long long ans=0;
	while (1)
	{
		long long tmp=0;
		for (int i=0;i<n;i++)
		tmp+=arr[i]/n;
		if (!tmp)
		{
			printf("%lld",ans);
			return 0;
		}
		ans+=tmp;
		for (int i=0;i<n;i++)
		arr[i]+=tmp-(arr[i]/n)*(n+1);
	}
}