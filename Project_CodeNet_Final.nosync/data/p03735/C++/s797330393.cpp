#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 

using namespace std;

const long long inf = 0x7fffffffffffffff;

struct node
{
	long long r,b;
}bag[200100];

long long n;
long long ans = inf,rmax,rmin = inf,bmax,bmin = inf;

bool cmp(node a,node b)
{
	return a.b < b.b;
}

int main()
{
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		bag[i].r = max(a, b);
		bag[i].b = min(a, b);
		rmax = max(bag[i].r,rmax);
		rmin = min(bag[i].r,rmin);
		bmax = max(bag[i].b,bmax);
		bmin = min(bag[i].b,bmin);
	}
	ans = (rmax - rmin) * (bmax - bmin);
	sort(bag + 1,bag + 1 + n,cmp);
	if(rmin > bmax)
	{
		printf("%lld\n",ans);
		return 0;
	}
	rmin = bmin;
	bmin = bag[1].r;
	bmax = max(bag[1].r,bmax);
	int i;
	for(i = 2;i < n;i++)
	{
		bmin = min(bmin,bag[i].r);
		bmax = max(bmax,bag[i].r);
		ans = min(ans,(bmax - min(bmin, bag[i + 1].b)) * (rmax - rmin));
	}
	if(i != n)
		printf("%lld\n",min(ans,(bmax - min(bmin, bag[i + 1].b)) * (rmax - rmin)));
	else
		printf("%lld\n",min(ans,(bmax - bmin) * (rmax - rmin)));
	return 0;
}