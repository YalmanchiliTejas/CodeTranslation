#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
const int N = 2e5+ 2, mod = 1e9 + 7;


void solve() {
	int n;
	cin >> n;
	ll s = 0;
	ll ans = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < n; i++) {
		s -= a[i];
		ans = (ans%mod) + (s%mod)*(a[i]%mod);
		ans %= mod;
	}
	cout << ans;
}

int main() {
	// reopen("input.txt", "r", stdin); 
 //    freopen("output.txt", "w", stdout); 
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		// cout << "Case #:" << tc << " ";
		solve();
	}
}