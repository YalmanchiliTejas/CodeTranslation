#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	LL ans=0;
	for (int i=k+1;i<=n;i++)
	{
		ans+=i-max(k,1);
		ans+=(LL)(n/i-1)*(i-k);
		ans+=max(0,n%i-k+1);
	}
	printf("%lld",ans);
	return 0;
}