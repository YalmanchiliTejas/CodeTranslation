#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	if(m==0)
	{
		ll ans=n*n;
		printf("%lld\n",ans);
		return 0;
	}
	ll ans=(n-m+1)*(n-m)/2;
	for(int i=m+1;i<=n-m;i++)
	{
		int k=i+m;
		while(k<=n)
		{
			ans+=min(k-m+i,n+1)-k;
			k+=i;
		}
	}
	printf("%lld\n",ans);
	return 0;
}