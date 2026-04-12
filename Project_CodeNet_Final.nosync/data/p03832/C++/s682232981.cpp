//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 1000 + 20 , mod = 1e9 + 7 ;
int n , a , b , c , d , dp[N][N] ;
int C[N][N] , rev[N] ;

inline void add (int &a , int b) {
	a += b ;
	if (a >= mod) a -= mod ;
}

inline int pw (int a , int b) {
	int res = 1 ;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod ;
		a = 1ll * a * a % mod ;
		b >>= 1 ;
	}
	return res ;
}

inline void pre () {
	for (int i = 0 ; i < N ; i ++) {
		C[i][0] = C[i][i] = 1 ;

		for (int j = 1 ; j < i ; j ++) {
			C[i][j] = C[i - 1][j] ;
			add(C[i][j] , C[i - 1][j - 1]) ;
		}

		rev[i] = pw(i , mod - 2) ;
	}
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	pre() ;

	cin >> n >> a >> b >> c >> d ;

	dp[n][0] = 1 ;
	
	for (int x = a ; x <= b ; x ++) {
		for (int i = 1 ; i <= n / x ; i ++) {
			for (int sum = 0 ; sum + x <= n ; sum ++) {
				add(dp[sum][i] , 1ll * C[sum + x][x] * dp[sum + x][i - 1] % mod * rev[i] % mod) ;	
			}
		}

		for (int i = 1 ; i <= n / x ; i ++) {
			for (int sum = 0 ; sum <= n ; sum ++) {
				if (c <= i && i <= d) add(dp[sum][0], dp[sum][i]) ;
				dp[sum][i] = 0 ;
			}
		}
	}

	cout << dp[0][0] << '\n' ;
}
