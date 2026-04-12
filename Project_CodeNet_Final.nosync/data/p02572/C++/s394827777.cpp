#include <bits/stdc++.h>
using namespace std;

#define ll long long		

const ll mod = (ll) 1e9 + 7;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C1.out", "w", stdout);
	
	
	
	int n;
	cin >> n;
	vector<int> a(n + 1);


	vector<ll> s(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	
	/*
	
	i = 1 ... n - 1, j = i + 1 ... n    sigma( ai * aj )
	
	( a1 * a2 + a1 * a3 + .. + a1 * an ) + ( a2 * a3 + a2 * a4 + ... + a2 * an ) + ( a3 * a4 + a3 * a5 + ... )
	use prefix sum
	
	
	a1 * ( a2 + a3 + ... + an ) + a2 * ( a3 + a4 * ... + an ) + a3 * ( a4 + a5 + a6 + ... + an ) + ...
	
	*/
	
	
	ll ans = 0;
	
	for (int i = 1; i < n; i++) {
		ans = (ans + (s[n] - s[i]) % mod * a[i]) % mod;
		
		//cout << (s[n] - s[i]) % mod * a[i] << endl;
		// 2 * 1e9 * 1e9 * 1e5 > LLONG_MAX
	}
	
	cout << ans;
}
