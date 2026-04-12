#include<bits/stdc++.h>

using namespace std;

long long num[200010],zzs[200010];

int main()
{
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		zzs[i]=zzs[i-1]+num[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans+=(num[i]%1000000007)*((zzs[n]-zzs[i])%1000000007);
		ans%=1000000007;
	}
	printf("%lld\n",ans);
	return 0;
}