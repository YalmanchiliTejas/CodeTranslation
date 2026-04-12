#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const long long inf=0x3f3f3f3f;
const long long Maxn=200000+10;
const long long mod=1000000000+7;
long long a[Maxn],s[Maxn],tot;
long long n,ans;
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		s[i]=(s[i-1]+a[i])%mod;
	}
	for(long long i=1;i<=n;++i)
	ans=(ans+(a[i]*s[i-1])%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}