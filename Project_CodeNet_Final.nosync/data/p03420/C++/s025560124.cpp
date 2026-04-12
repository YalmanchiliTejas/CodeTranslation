#include <cstdio>
#include <algorithm>

using namespace std;

int i,m,n;
long long s;

int main()
{
	scanf("%d%d",&n,&m);
	for (i=m+1;i<=n;i++)
	{
		s=s+1LL*(n/i)*(i-m);
		s=s+max(n%i-m+1,0);
		if (! m)
			s--;
	}
	printf("%lld",s);
	return 0;
}