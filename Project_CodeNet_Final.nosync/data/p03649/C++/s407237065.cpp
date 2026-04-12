#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

int n; ll A[55],sum;
inline bool check(ll x)
{
	if(x<0) return 0;
	ll al=0;
	for(int i=1;i<=n;i++)
	{
		ll sp=A[i]+x-n;
		if(sp<0) al+=0;
		else 
		{
			if(x-sp/(n+1)-1>=al) al+=sp/(n+1)+1;
			else return 0;
		}
	}
	return 1;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	for(int i=1;i<=n;i++) sum+=A[i];
	for(int i=n*n-n;i>=0;i--)
	{
		if(check(sum-1ll*i))
		{
			printf("%lld\n",sum-1ll*i);
			return 0;
		}
	}
	assert(0);
	return 0;
}
