#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long ll;
const int MAXN = 55;
int nowarn;

int n;
ll a[MAXN];

ll check( ll x ) {
	ll ans = 0;
	for( int i = 0; i < n; ++i ) {
		if( a[i] <= x ) continue;
		ans += (a[i]-x-1) / (n+1) + 1;
	}
	return ans;
}
ll solve1() {
	ll ans = -n*n + n;
	for( int i = 0; i < n; ++i ) ans += a[i];
	if( ans <= 0 ) return 0;
	ll rtn = ans;
	for( int i = 0; i < n; ++i ) a[i] += ans;
	ll low = 0, high = *max_element(a, a+n);
	while( low < high ) {
		ll mid = (low + high) / 2;
		if( check(mid) > ans ) low = mid + 1;
		else high = mid;
	}
	for( int i = 0; i < n; ++i ) {
		if( a[i] <= low ) continue;
		ll t = (a[i]-low-1) / (n+1) + 1;
		ans -= t, a[i] -= t*(n+1);
	}
	while( ans-- ) {
		int p = int(max_element(a, a+n) - a);
		a[p] -= n+1;
	}
	return rtn;
}

ll solve2() {
	ll ans = 0;
	while(1) {
		int p = int(max_element(a, a+n) - a);
		if( a[p] <= n-1 ) return ans;
		for( int i = 0; i < n; ++i )
			a[i] += (i == p ? -n : 1);
		++ans;
	}
	return -1;
}

int main() {
	nowarn = scanf( "%d", &n );
	for( int i = 0; i < n; ++i ) nowarn = scanf( "%lld", a+i );
	ll ans = solve1() + solve2();
	printf( "%lld\n", ans );
	return 0;
}
