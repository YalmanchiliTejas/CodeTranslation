#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(void)
{
	ll i,ans,n,k,count,num;
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		ans=0;
		count=1;
		if(k==0)
		{
			ans=n*n;
			printf("%lld\n",ans);
			continue;
		}
		for(i=k+1;i<=n;i++)
		{
			num=n%i;
			if((num-k+1)>0)
			ans+=(num-k+1);
			ans+=(count++)*((n-num)/i);
		}
		printf("%lld\n",ans);
	}
 } 