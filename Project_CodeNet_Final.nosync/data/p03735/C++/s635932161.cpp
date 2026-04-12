//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 2e5 + 20 , inf = 1e9 + 20 ;
int n ;
pii a[N] ;

ll ans ;
int mn1 = inf , mx1 , mn2 = inf , mx2 ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;

	for (int i = 0 ; i < n ; i ++) {
		cin >> a[i].F >> a[i].S ;

		if (a[i].F > a[i].S) swap(a[i].F , a[i].S) ;
	
		mn1 = min(mn1 , a[i].F) ;
		mx1 = max(mx1 , a[i].F) ;

		mn2 = min(mn2 , a[i].S) ;
		mx2 = max(mx2 , a[i].S) ;
	}

	ans = 1ll * (mx1 - mn1) * (mx2 - mn2) ;

	sort(a , a + n) ;

	mx1 = mx2 ;
	mn2 = inf , mx2 = 0 ;

	for (int i = 0 ; i < n ; i ++) {
		if (i) ans = min(ans , 1ll * (mx1 - mn1) * (max(mx2 , a[n - 1].F) - min(mn2 , a[i].F))) ;

		mn2 = min(mn2 , a[i].S) ;
		mx2 = max(mx2 , a[i].S) ;
	}

	cout << ans << '\n' ;
}