#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 1e9 + 7;

signed main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> sum(n);
	int prev = 0;
	for (int i = 0; i < n; ++i) {
		sum[i] = prev + a[i];
		sum[i] %= mod;
		prev = sum[i];
	}
	long long res = 0;
	for (int i = n-1; i > 0; --i) {
		res += a[i] * sum[i-1];
		res %= mod;
	}
	cout << res << endl;
}
