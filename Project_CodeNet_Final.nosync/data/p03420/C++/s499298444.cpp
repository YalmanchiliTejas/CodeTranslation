#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(!k){printf("%lld",1ll*n*n);return 0;}
	ll ans=0;
	for(int i=k+1;i<=n;i++)
	{
	   ans+=(ll)(n/i)*(i-k);
	   ans+=max((ll)(n%i-k+1),0ll);
	}
	printf("%lld",ans);
	return 0;
}