#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#define gI gi
#define itn int
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)

using namespace std;

typedef long long ll;

inline ll gi()
{
    ll f = 1, x = 0; char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return f * x;
}

const ll INF = 2000000007;

ll n, m, lmax, lmin = INF, rmax, rmin = INF, ans, sum, minn[200003], maxx[200003];
ll ans1, ans2;
struct Node
{
	ll x, y;
} a[200003];

inline bool cmp(Node xx, Node yy)
{
	if (xx.x != yy.x) return xx.x < yy.x;
	return xx.y < yy.y;
}

int main()
{
	//File("D");
	n = gi();
	for (ll i = 1; i <= n; i+=1)
	{
		a[i].x = gi(), a[i].y = gi();
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
		lmin = min(lmin, a[i].y), lmax = max(lmax, a[i].y);
		rmin = min(rmin, a[i].x), rmax = max(rmax, a[i].x);
	}
	ans1 = (lmax - lmin) * (rmax - rmin);
	lmin = rmin;
	sort(a + 1, a + 1 + n, cmp);
	minn[1] = maxx[1] = a[1].y;
	ans2 = INF;
	for (ll i = 2; i <= n; i+=1)
	{
		minn[i] = min(minn[i - 1], a[i].y);
		maxx[i] = max(maxx[i - 1], a[i].y);
		if (i != n) ans2 = min(ans2, max(maxx[i], a[n].x) - min(minn[i], a[i + 1].x));
	}
	ans2 = ans2 * (lmax - lmin);
	printf("%lld\n", min(ans2, ans1));
	return 0;
}
