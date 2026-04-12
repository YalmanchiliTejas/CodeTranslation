#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long a[200001],d[200001];
long long mod=1000000007;
int main()
{
	long long n;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		d[i]=(d[i-1]+a[i])%mod;
	}
	long long sum=0;
	for(long long i=n;i>=2;i--)
	{
		sum=(sum+(a[i]*d[i-1])%mod)%mod;
	}
	printf("%lld\n",sum%mod);
	return 0;
}