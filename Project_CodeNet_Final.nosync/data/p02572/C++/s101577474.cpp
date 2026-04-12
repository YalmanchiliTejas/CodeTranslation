#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n;
const LL mod=1e9+7;
LL sum1,sum2;
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		LL t;
		scanf("%lld",&t);
		sum1=(sum1+t*t)%mod;
		sum2+=t;
	}
	sum2%=mod;
	printf("%lld\n",(sum2*sum2-sum1+mod)%mod*(mod+1>>1)%mod);
	return 0;
}