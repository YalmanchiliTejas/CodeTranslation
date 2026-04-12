#include <bits/stdc++.h>
using namespace std;
						
#define fast_cin() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define int long long

const int mod = 1e9 + 7;
				
int32_t main() {
	fast_cin();  
	int n;
	cin >> n;
	int sum = 0;
	vector<int> a(n);
	for (int &i : a) cin >> i, sum += i, sum %= mod;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		sum -= a[i];
		sum += mod, sum %= mod;
		ans += (sum * a[i]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}