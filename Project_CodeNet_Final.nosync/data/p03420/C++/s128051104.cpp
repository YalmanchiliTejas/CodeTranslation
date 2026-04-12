#include <iostream>
#include <stdio.h>
#include <string.h>
#define int long long

using namespace std;

int n,k,ans=0;

signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int b=k+1;b<=n;b++)
	{
		for(int d=0;b*d+k<=n;d++)
		{
			ans+=min((d+1)*b-1,n)-max(b*d+k,1ll)+1;
		}
	}
	printf("%lld\n",ans);
}
