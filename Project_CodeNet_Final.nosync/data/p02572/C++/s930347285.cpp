#include <bits/stdc++.h>

using namespace std;

#define int 		long long
#define endl 		"\n"
#define mod 		1000000007
#define inf 		1e18
#define IOS 		ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int32_t main() {

	IOS;

	int n;
	cin >> n;

	vector<int> v(n), suf(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	suf[n - 1] = v[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		suf[i] = (v[i] + suf[i + 1]) % mod;
	}

	int ans = 0;

	for (int i = 0; i < n - 1; i++) {
		ans = (ans + v[i] * suf[i + 1]) % mod;
	}

	cout << ans;

	return 0;
}