#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
ll n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k==0) 
	{
		return printf("%lld\n",n*n),0;
	}
	ll ans=0;
	for(int i=k+1;i<=n;i++)
	{
		for(int j=k;j<=n;j+=i)
		{
			int nex=min(n,(j+(i-k-1)));
			ans+=(nex-j+1);
		}
	}
	printf("%lld\n",ans);
}
