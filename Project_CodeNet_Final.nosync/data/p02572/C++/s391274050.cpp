#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ld  = long double;
using pii = pair<int,int>;

void solve(){
	constexpr int MOD = 1e9 + 7;

	int n;
	cin >> n;

	vector<ll> arr(n);
	for(auto& i : arr) cin >> i;

	auto presum = arr;
	partial_sum(presum.rbegin(), presum.rend(), presum.rbegin());
	for(auto& i : presum) i %= MOD;

	ll ans = 0;

	for(int i = 0; i < n - 1; ++i)
		ans = (ans + arr[i] * presum[i + 1]) % MOD;

	cout << ans << "\n";
}

signed main (void){
	// Fast_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Set Fixed Notation (default sucks), High Precision for Floating-Point Output
	cout << fixed << setprecision(20);

	// Multiple TCs
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
}
