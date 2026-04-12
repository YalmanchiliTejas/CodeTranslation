#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a ; i <= b; ++ i) 
const int N = 500005, inf = 1000000007 ;
using namespace std ;

int h[N], n ;
struct poi {
	int x, y ; 
} a[N], b[N] ;

bool cmpx(poi a, poi b) {
	return a.x < b.x ;
}

bool cmpy(poi a, poi b) {
	return a.y < b.y ;
}

int main() {
	scanf("%d", &n) ;
	int mn = inf, mx = - inf ;
	rep(i, 1, n) {
		scanf("%d%d", &a[i].x, &a[i].y) ;
		mn = min(mn, min(a[i].x, a[i].y)) ;
		mx = max(mx, max(a[i].x, a[i].y)) ;
		b[i << 1].x = a[i].x, b[i << 1].y = i ;
		b[(i << 1) - 1].x = a[i].y, b[(i << 1) - 1].y = i ;
	}
	ll ans = (ll) inf * inf ;
	sort(b + 1, b + 2 * n + 1, cmpx) ;
	int r = 1, cnt = 0 ;
	rep(l, 1, 2 * n) {
		for ( ; r <= 2 * n && cnt < n; ++ r) {
			++ h[b[r].y] ;
			cnt += h[b[r].y] == 1 ;
		}
		if (cnt == n) ans = min(ans, (ll) (mx - mn) * (b[r - 1].x - b[l].x)) ;
		-- h[b[l].y] ;
		cnt -= h[b[l].y] == 0 ;
	}
	rep(i, 1, n) {
		if (a[i].x > a[i].y) swap(a[i].x, a[i].y) ;
	}
	sort(a + 1, a + n + 1, cmpx) ;
	mn = a[n].x - a[1].x ;
	sort(a + 1, a + n + 1, cmpy) ;
	mx = a[n].y - a[1].y ;
	ans = min(ans, (ll) mn * mx) ;
	printf("%lld\n", ans) ;
	return 0 ;
}