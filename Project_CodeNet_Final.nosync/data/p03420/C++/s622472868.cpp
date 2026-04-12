#include<cstdio>	
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,k,ans;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(LL i=n;i>k;i--)
	{
		LL x=n/i;
		ans+=(i-k)*x;
		LL y=n-i*x-k;
		if(k)
			y++;
		ans+=y>0?y:0;
	}
	printf("%lld",ans);
}