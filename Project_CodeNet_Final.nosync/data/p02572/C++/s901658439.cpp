#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	vector<ll> a(n);
	for(auto& e:a) cin >> e;
	vector<ll> p(n);
	p[0] = a[0];
	for (int i=1; i<n; i++) {
		p[i] = a[i] + p[i-1];
	}
	
	ll ans = 0;
	for (int i=1; i<n; i++) {
		ans += (a[i]%MOD)*(p[i-1]%MOD);
		ans %= MOD;
	}
	
	cout << ans << '\n';
	return 0;
}


