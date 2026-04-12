#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int sum = 0 ;
	int ans = 0 ;
	int mod = 1e9 + 7 ;
	for(int i = 0 ; i < n ; i++){
		int x ; cin >> x ;
		ans = (ans + x*sum) % mod ;
		sum = (sum + x) % mod ;
	}
	cout << ans ;
	return 0 ;
}

