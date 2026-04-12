#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

void solution(){
	int mod = 1e9 + 7;
	int n; cin >> n;
	vector<ll> a(n); for(auto& x : a) cin >> x;
	ll s = 0;
	for(ll x : a) s += x;
	s %= mod;
	ll ans = 0;
	for(ll x : a){
		s = (s - x + mod) % mod;
		ans = (ans + x * (s + mod) % mod) % mod;
	}
	cout << ans << endl;
}	


int main(){ 
	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}