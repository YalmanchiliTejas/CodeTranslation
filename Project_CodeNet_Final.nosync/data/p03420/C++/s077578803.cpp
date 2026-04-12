/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k,sum=0;scanf("%lld%lld",&n,&k);
	if(k==0)
	{
		printf("%lld\n",n*n);
		return 0;
	}
	for(int b=k+1;b<=n;b++)
	{
		int a=n%b;
		sum+=a-k>=0? a-k+1:0;
		sum+=n/b*(b-k);
	}
	printf("%lld\n",sum);
	return 0;
}
