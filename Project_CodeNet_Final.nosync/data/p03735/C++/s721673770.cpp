#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 5e5 + 5;
typedef long long ll; 
using namespace std;

int n, l, r, mn, mx, cnt;
struct node { int x, y; } p[N], q[N];
ll ans = 0x3f3f3f3f3f3f3f3f; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

bool cmp(node a, node b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }

bool cmp1(node a, node b) { return a.y == b.y ? a.x > b.x : a.y < b.y; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> ();
	for(int i = 1; i <= n; i++)
	{
		p[i].x = read <int> (), p[i].y = read <int> ();
		if(p[i].x > p[i].y) swap(p[i].x, p[i].y);
		if(p[i].x < p[mn].x || !mn) mn = i;
		if(p[i].y > p[mx].y || !mx) mx = i; 
	}
	if(mn != mx)
	{
		l = p[mn].y, r = p[mx].x; if(l > r) swap(l, r); 
		for(int i = 1; i <= n; i++)
		{
			if(i == mn || i == mx) continue; 
			if(p[i].y < l) l = p[i].y; 
			else if(p[i].x > r) r = p[i].x; 
		}
		for(int i = 1; i <= n; i++) if(p[i].x < l && p[i].y > r) q[++cnt] = p[i]; 
		sort(q + 1, q + cnt + 1, cmp1); 
		for(int tmp = 0x3f3f3f3f, i = cnt; i >= 1; i--)
			ans = min(ans, 1ll * (p[mx].y - p[mn].x) * (q[i].y - l)), tmp = min(tmp, q[i].x), l = min(l, tmp); 
		ans = min(ans, 1ll * (p[mx].y - p[mn].x) * (r - l)); 
	}
	sort(p + 1, p + n + 1, cmp), mn = mx = 0;
	for(int i = 1; i <= n; i++)
	{
		if(p[i].x < p[mn].x || !mn) mn = i;
		if(p[i].y > p[mx].y || !mx) mx = i; 		
	}
	r = p[mx].x, l = p[mn].y;
	for(int i = 1; i <= n; i++)
	{
		if(i == mn || i == mx) continue;
		l = min(l, p[i].y), r = max(r, p[i].x); 
	}
	ans = min(ans, 1ll * (p[mx].y - l) * (r - p[mn].x));
	printf("%lld\n", ans); 
	return 0; 
}
