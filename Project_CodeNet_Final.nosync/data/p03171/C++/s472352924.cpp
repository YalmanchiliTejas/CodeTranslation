#include <bits/stdc++.h>

using namespace std ;

#define ll long long

// int a[] = { 8, 15, 3, 7 };
vector <ll> a(30001) ;

ll dp[3001][3001] ;

ll rec (int i , int j) {
	if (i > j) return 0 ;
	if (dp[i][j] != -1)return dp[i][j] ;
	return dp[i][j] =  max (a[i] + min(rec(i + 2, j) , rec(i + 1, j - 1)) , a[j] + min(rec(i , j - 2) , rec(i + 1, j - 1)) ) ;
}

int main () {
	memset(dp, -1, sizeof(dp)) ;
	int n ;
	cin >> n ;
	ll sum = 0 ;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i] ;
		sum += a[i] ;
	}
	ll x = rec(0, n - 1) ;
	ll y = sum - x ;
	cout << x - y  ;
	return 0 ;
}