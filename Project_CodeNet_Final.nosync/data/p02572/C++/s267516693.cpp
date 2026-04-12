#include "bits/stdc++.h"
using namespace std ;
typedef long long int ll ;
ll mod = 1e9 + 7 ;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll sum = 0 , n , ans = 0 ;
	cin >> n ;
	vector<ll> v(n, 0);

	for(auto &i : v) {
		cin >> i ;
		sum += i ;
	}
	for(auto &i : v){
		sum -= i ;
		sum = (sum+mod)%mod;
		ans = (ans + (i*sum)%mod)%mod;
	}
	ans = (ans + mod)%mod;
	cout << ans ;

}