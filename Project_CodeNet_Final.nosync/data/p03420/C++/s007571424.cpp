#include<cstdio>
#include<iostream>
using namespace std;
int i,n,m;
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=m+1;i<=n;i++)
		if(m)ans+=1ll*(n/i)*(i-m)+max((n%i-m+1),0);else
		ans+=1ll*(n/i)*(i-m)+max((n%i-m),0);
	printf("%lld\n",ans);
}