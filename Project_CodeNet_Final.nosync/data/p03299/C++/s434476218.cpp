//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const N = 100 + 10 , mod = 1e9 + 7 ;
int n , h[N] ;

int inv2 = (mod + 1) >> 1 ;

int z = 1 ;
set <pii> dp ;

inline void add (int &a , int b) {
	a += b ;
	if (a >= mod) a -= mod ;
}

inline int pw (int a , int b) {
	int res = 1 ;
	for (; b ; b >>= 1 , a = 1ll * a * a % mod) 
		if (b & 1) res = 1ll * res * a % mod ;
	return res ;
}

inline int get (int start , int len) {
	return (2 * start - (2ll * start * pw(inv2 , len)) % mod + mod) % mod ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;
	
	cin >> n ;
	for (int i = 0 ; i < n ; i ++) cin >> h[i] ;

	if (h[0] > 1) dp.insert({1 , pw(2 , h[0] - 1)}) ; 
	dp.insert({h[0] , 2}) ;

	for (int i = 1 ; i < n ; i ++) {
		if (h[i - 1] >= h[i]) {
			int sum = 0 , last = h[i - 1] + 1 ;
			while (dp.size() && dp.rbegin() -> F > h[i]) {
				pii p = *dp.rbegin() ;
	
				add(sum , get(p.S , last - p.F)) ;

				last = p.F ;

				dp.erase(p) ;
			}

			if (dp.size()) {
				pii p = *dp.rbegin() ;
				add(sum , get(1ll * p.S * pw(inv2 , h[i] - p.F) % mod , last - h[i])) ;
				if (p.F == h[i]) dp.erase(p) ;
			}

			add(sum , sum) ;

			dp.insert({h[i] , sum}) ; 
		}
		else {
			z = 1ll * z * pw(2 , h[i] - h[i - 1]) % mod ;

			pii p = *dp.rbegin() ;

			assert(p.F == h[i - 1]) ;

			dp.insert({h[i] , 2ll * p.S * pw(inv2 , h[i] - h[i - 1]) % mod}) ;
		}
	}

	int last = h[n - 1] + 1 , ans = 0 ;
	while (_sz(dp)) {
		pii p = *dp.rbegin() ;
	
		add(ans , get(p.S , last - p.F)) ;

		last = p.F ;

		dp.erase(p) ;
	}

	ans = 1ll * ans * z % mod ;

	cout << ans << '\n' ;
}
