#include<cstdio>
#include<cstring>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
LL n,k;
int main()
{
	LL ans=0;scanf("%lld %lld",&n,&k);
	if(k==0) {printf("%lld",n*n);return 0;}
	for(LL i=k+1;i<=n;i++)
	{
		LL t=n/i,y=n%i;
		if(y>=k)
		{
			if(y==0) ans+=t*(y-k+1);
			else ans+=(t+1)*(y-k+1);
		}
		ans+=t*(i-1-max(k,y));
		if(y<k) ans+=t;
		//printf("%lld %lld\n",i,ans);
	}
	printf("%lld\n",ans);
}