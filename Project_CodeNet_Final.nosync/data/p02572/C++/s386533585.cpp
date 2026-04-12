/*******************************************************************
 * 		Author : yash1402_										   *
 ******************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

#define MOD 1000000007

void solve() {
	ll n;
	cin >> n;
	vll v(n);
	
	for(auto &i:v) cin >> i;
	
	ll s=0,ans = 0;
	
	for(ll i=0;i<n;i++) {
		s = s+v[i];
	}
	
	for(ll i=0;i<n-1;i++) {
		s -= v[i];
		ans = (ans + (( (v[i]%MOD)*(s%MOD) )%MOD))%MOD;
	}
	
	cout << ans << "\n";
}

int main() {
	ll T=1;
	//cin >> T;
	while(T--) {
		solve();
	}
}

