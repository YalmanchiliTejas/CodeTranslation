#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
long long ans;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=k+1;i<=n;i++)
	{
		ans=ans+(i-k)*(n/i);
		if(k)ans=ans+max((n%i)-k+1,0);
		else ans=ans+max((n%i)-k,0);
	}
	printf("%lld\n",ans);return 0;
}