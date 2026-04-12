#include<iostream>
#include<cstdio>
using namespace std;

int A[200005];
int mod = 1e9 + 7;

int main()
{
	int n;
	scanf("%d",&n);
	long long sum=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&A[i]);
		sum+=A[i];
	}		
	for(int i=1;i<=n-1;++i)
	{
		sum-=A[i];
		ans+=sum % mod*A[i]%mod;
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}