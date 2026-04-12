#include<cstdio>
#include<algorithm>
using namespace std;
long long n,k,ans;
int main()
{
	scanf("%lld%lld",&n,&k);
	if(!k)printf("%lld\n",n*n);
	else
	{
		for(long long b=k+1;b<=n;b++)
		{
			long long a=n%b;
			if(a>=k)ans+=a-k+1;
			ans+=n/b*(b-k);
		}
		printf("%lld\n",ans);
	}
}
