#include<iostream>
#include<cstdio>
#include<cstring>

typedef long long ll;
int n,k;

int main()
{
	scanf("%d%d",&n,&k);
	ll ans=0;

	for(int i=k+1;i<=n;i++)
	{
		ll cnt=i-k,d=n/i,r=n%i;

		ans+=cnt*d;

		if(k)ans+=std::max(0ll,r-k+1);
		else ans+=r;

	}
	printf("%lld\n",ans);

	return 0;
}
