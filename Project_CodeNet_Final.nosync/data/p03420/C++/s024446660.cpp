#include <bits/stdc++.h>
#define LL long long
using namespace std ;
void Read ( LL &x, char c = getchar(), bool f = 0 ) {
	for ( x = 0 ; !isdigit(c) ; c = getchar() ) if (c == '-') f = 1 ;
	for ( ; isdigit(c) ; c = getchar() ) x = 10*x + c - '0' ;
	if (f) x = -x ;
}
LL n, k, a, b ;
LL Find ( LL x ) {
	LL l = 1, r = b-1, mid, rec = b ;
	while (l <= r) {
		mid = (l+r)>>1 ;
		if ((n-mid)/b <= x) rec = mid, r = mid-1 ;
		else l = mid+1 ;
	}
	return rec ;
}
int main() {
	LL ans = 0, t, r ;
	Read(n), Read(k) ;
	for ( b = k+1 ; b <= n ; b ++ ) {
		t = (n-k)/b ;
		r = Find(t-1) ;
		ans += (r-k)*(t+1) + (b-r)*t ;
	}
	if (k == 0) ans -= n ;
	cout << ans << endl ;
	return 0 ;
}