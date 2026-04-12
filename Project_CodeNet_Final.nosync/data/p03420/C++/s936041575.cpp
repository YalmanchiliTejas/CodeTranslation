#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,cnt,ans;
int main()
{
	int i,s,a,b,j,k;
	scanf("%lld%lld",&n,&m);
	for(i=m;i<=n;i++)
	{
		a=n-i;
		for(s=i+1;s<=a;s=j+1)j=a/(a/s),ans+=(j-s+1)*(a/s+1);
		ans+=n-s+1;
	}
	if(!m)ans-=n;
	printf("%lld",ans);
	return 0;
}