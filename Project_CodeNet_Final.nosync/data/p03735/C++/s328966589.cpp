#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 

using namespace std;

const long long inf = 0x7fffffffffffffffll;

struct node
{
	long long r,b;
}bag[200100];

long long n;
long long ans = inf,rmax,rmin = inf,bmax,bmin = inf;
long long mi[200100],ma[200100];

bool cmp(node a,node b)
{
	return a.b < b.b;
}

int main()
{
	// freopen("c.in","r",stdin);
	// freopen("c.out","w",stdout);
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
	ma[1] = bag[1].r;mi[1] = bag[1].r;
	for(int i = 2;i <= n;i++)
		ma[i] = max(ma[i - 1],bag[i].r),
		mi[i] = min(mi[i - 1],bag[i].r);
	int tmp = 1;
	rmin = bmin;
	bmax = max(bag[1].r,bmax);
	bmin = min(bag[2].b,bag[1].r);
	for(int i = 2;i <= n;i++)
	{
		ans = min(ans,(bmax - bmin) * (rmax - rmin));
		bmax = max(bmax,ma[i]);
		bmin = min(bag[i + 1].b,mi[i]);
	}
	printf("%lld\n",ans);
	return 0;
}