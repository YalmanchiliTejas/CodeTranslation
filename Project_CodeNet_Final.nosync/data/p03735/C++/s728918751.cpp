#include <cstdio>
#include <algorithm>

#define maxn 200010
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
#define cmax(_a, _b) (_a < (_b) ? _a = (_b) : 0)
typedef long long ll;
std::pair<int, int> a[maxn];
#define fir first
#define sec second
int main()
{
	int n, maxx = 0, minn = 0x7fffffff;
	ll ans = ~0ULL >> 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &a[i].fir, &a[i].sec);
		a[i].fir > a[i].sec ? std::swap(a[i].fir, a[i].sec), 1 : 0;
		cmax(maxx, a[i].sec);
		cmin(minn, a[i].fir);
	}
	int rmin = minn, rmax = 0, bmin = 0x7fffffff, bmax = maxx;
	for (int i = 1; i <= n; ++i)
	{
		cmax(rmax, a[i].fir);
		cmin(bmin, a[i].sec);
	}
//	printf("%d %d %d %d\n", rmin, rmax, bmin, bmax);
	cmin(ans, 1ll * (rmax - rmin) * (bmax - bmin));

	std::sort(a + 1, a + n + 1);
	rmax = maxx;
	int bbmin = 0x7fffffff; bmin = 0x7fffffff; bmax = a[n].fir;
	for (int i = 1; i < n; ++i)
	{
		bmin = a[i + 1].fir;
		cmin(bbmin, a[i].sec);
		cmax(bmax, a[i].sec);
		cmin(ans, 1ll * (rmax - rmin) * (bmax - std::min(bmin, bbmin)));
	}
	printf("%lld\n", ans);
	return 0;
}