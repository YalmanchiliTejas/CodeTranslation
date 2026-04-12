#include<bits/stdc++.h>
#pragma GCC optimize("trapv")
#define I inline void 
#define S struct 
#define vi vector<int> 

using namespace std ; 
using ll = long long ; 
using ld = long double ; 

const int N = 1e5 + 7 , mod = 1e9 + 7 ; 
int n ; 

// How interesting!

int main(){
	ios_base::sync_with_stdio(0) ; 
	cin.tie(0) ;
	//freopen("in.in" , "r" , stdin) ; 

	ll sum = 0 ; 
	ll ans = 0 ; 
	cin >> n ; 
	for(int i = 0 ;i < n;i++){
		ll x ;
		cin >> x; 
		ans += x * sum ; 
		sum%= mod ; 
		ans%= mod ; 
		sum+= x ; 
	}
	cout<< ans ; 
	return 0 ; 
}
