#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
int32_t main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int sum = accumulate(arr.begin(), arr.end(), 0ll) % MOD, ans = 0;
	for(int i=0; i<n; i++) {
		sum -= arr[i];
		sum += MOD;
		sum %= MOD;
		ans += arr[i] * sum;
		ans %= MOD;
	}
	cout << ans;
}