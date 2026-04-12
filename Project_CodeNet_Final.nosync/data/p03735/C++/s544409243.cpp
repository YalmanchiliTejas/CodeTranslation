#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200005
#define INF 1061109567
using namespace std;

int n, lmax, lmin, rmax, rmin;
long long ans1, ans2; 
struct node
{
	int x, y; 
} a[N]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	return x * w; 
}

bool cmp(node x, node y)
{
	return x.x < y.x; 
}

int main()
{
	n = read <int> ();
	lmax = rmax = -INF, lmin = rmin = INF; 
	for(int i = 1; i <= n; i++)
	{
		a[i].x = read <int> (), a[i].y = read <int> ();
		if(a[i].x > a[i].y) swap(a[i].x, a[i].y);
		lmax = max(lmax, a[i].y);
		lmin = min(lmin, a[i].y);
		rmax = max(rmax, a[i].x);
		rmin = min(rmin, a[i].x); 
	}
	sort(a + 1, a + n + 1, cmp); 
	ans1 = 1ll * (lmax - lmin) * (rmax - rmin);
	ans2 = INF, lmin = rmin, rmin = rmax = a[1].y;
	for(int i = 2; i <= n; i++)
	{
		rmax = max(rmax, a[i].y); 
		rmin = min(rmin, a[i].y);
		if(i != n) ans2 = min(ans2, 1ll * max(rmax, a[n].x) - min(rmin, a[i + 1].x)); 
	}
	ans2 = 1ll * ans2 * (lmax - lmin);
	printf("%lld\n", min(ans1, ans2)); 
	return 0; 
}
