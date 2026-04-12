#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

vector<ll> lay(50+1), paty(50+1);

ll solve(ll n, ll x) {
	ll ans = 0;
	if(n == 1) {
		if(x == 1) ans  = 0;
		if(x == 2) ans  = 1;
		if(x == 3) ans  = 2;
		if(x == 4) ans  = 3;
		if(x == 5) ans  = 3;
	}
	else if(x == 1) ans += 0;
	else if(x > 1 && x < lay[n-1]+2) ans += solve(n-1, x-1);
	else if(x == lay[n-1]+2) ans += 1LL + solve(n-1, lay[n-1]);
	else if(x > lay[n-1]+2 &&x < lay[n]) ans += solve(n-1, x-lay[n-1]-2) + 1LL + solve(n-1, lay[n-1]);
	else if(x == lay[n]) ans += paty[n];
	return ans;
}

int main() {
	ll n, x;
	cin >> n >> x;
	
	lay[0] = 1;
	paty[0] = 1;
	rep(i, n) {
		lay[i+1] = 2 * lay[i] + 3;
		// cout << lay[i+1] << endl;
	}
	rep(i, n) {
		paty[i+1] = 2 * paty[i] + 1;
		// cout << paty[i+1] << endl;
	}
	cout << solve(n, x) << endl;
	
	return 0;
}