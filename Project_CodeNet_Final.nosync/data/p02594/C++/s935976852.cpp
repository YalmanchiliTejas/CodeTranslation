// Author: Harshdeep Sharma , IIT  Indore
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
// #define MOD  998244353
#define ll long long
const double PI = atan(1.0) * 4;
// const ll INF = (int)1e9 ;
const int di[4] = { -1, 0, 1, 0} ;
const int dj[4] = {0, -1, 0, 1} ;
const ll INF = (ll)2e18 + 50;
const int maximum  = numeric_limits<int>::min();
const int minimum  = numeric_limits<int>::max();




ll power(ll a , ll e) {
	ll res = 1LL ;
	while (e > 0) {
		if (e % 2 == 1) res = res * a;
		a =  a * a  ;
		e /= 2 ;
	}
	return res ;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t ;
	// cin >> t ;
	// while (t--) {
	// int n , d ;
	// cin >> n >> d ;
	// int ans = 0 ;
	// for (int i = 0 ; i < n ; i++) {
	// 	int x  , y ;
	// 	cin >> x >> y ;
	// 	if (sqrt(x * x + y * y + 0.0) >= d) {
	// 		ans++ ;
	// 	}
	// }
	// cout << ans << "\n";
	int x ; 
	cin >> x ; 
	if(x >= 30) {
		cout << "Yes\n";
	}else {
		cout << "No\n";
	}




	// }









	return 0 ;

}

