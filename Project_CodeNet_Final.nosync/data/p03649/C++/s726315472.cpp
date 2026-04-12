#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 55;
typedef long long ll;
const ll INF = 1e18; 
using namespace std;

int n;
ll a[N], ans = INF; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

int lowbit(int x) { return x & (-x); }

bool check(ll k)
{
	ll res = 0; 
	for(int i = 1; i <= n; i++)
		res += (k + a[i] + 1) / (n + 1); 
	return res <= k; 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> ();
	for(int i = 1; i <= n; i++) a[i] = read <ll> ();
	if(check(0)) { puts("0"); return 0; }
	for(int x = 0; x <= n; x++)
	{
		ll l = 0, r = (50ll * 10000000000000000 - x) / n, mid, tmp = 0; 
		while(l <= r)
		{
			mid = (l + r) >> 1; 
			if(check(mid * n + x)) tmp = mid, r = mid - 1; 
			else l = mid + 1; 
		}
		ans = min(ans, tmp * n + x); 
	}
	printf("%lld\n", ans); 
	return 0; 
}
