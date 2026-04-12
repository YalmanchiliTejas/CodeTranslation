#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	long long n,k,i,ans=0,x,r;
	scanf("%lld%lld",&n,&k);
	for(i=k+1;i<=n;i++)//i==b
	{
		x=n/i;r=n%i;
		if(r>=k)	ans+=x*(i-k)+r-k+1;
		else	ans+=x*(i-k);
	}
	if(k==0)	printf("%lld",n*n);
	else printf("%lld",ans);
	return 0;
}