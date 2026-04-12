#include<cstdio>
using namespace std;

const int N = 1e5;
long long n,m;

int main()
{
	scanf("%lld%lld",&n,&m);
	long long ans = 0ll;
	for(long long b=m+1ll; b<=n; b+=1ll)
	{
		long long r = n/b;
		ans += (b-m)*r;
		long long x = n-r*b;
		if(x>=m) ans += x-(m-1);
	}
	if(m==0) ans -= n;
	printf("%lld\n",ans);
	return 0;
}