#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define sz(x) int(x.size())
#define pb push_back
#define int long long

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (auto &it : a)
		cin >> it;
	// if (n%2 == 0) {
	// 	int sum[2] = {0};
	// 	for (int i = 0; i < n; ++i)
	// 		sum[i%2] += a[i];
	// 	cout << max(sum[1], sum[0]) << '\n';
	// 	return 0;
	// }
	vector<int> pref(n, 0), suf(n, 0);
	pref[0] = a[0];
	pref[1] = a[1];
	for (int i = 2; i < n; ++i)
		pref[i] = pref[i-2] + a[i];

	suf[n-1] = a[n-1];
	suf[n-2] = a[n-2];
	for (int i = n-3; i >= 0; --i)
		suf[i] = suf[i+2] + a[i];

	int ans = -1e18;
	if (n%2 == 0) {
		ans = max(pref[n-1], pref[n-2]);
		for (int i = 1; i+2 < n; i += 2) {
			int x = 0;
			if (i) x += pref[i-1];
			if (i+2 < n) x += suf[i+2];
			ans = max(ans, x);
		}
		cout << ans << '\n';
		return 0;
	}
	ans = pref[n-2];
	for (int i = 0; i+1 < n; ++i) {
		int x = 0;
		if (i) x += pref[i-1];
		if (i+2 < n) x += suf[i+2];
		ans = max(ans, x);

		if (i > 0 and i+2 < n) {
			x = 0;
			if (i) x += pref[i-1];
			if (i+3 < n) x += suf[i+3];
			ans = max(ans, x);
		}
	}
	// Skip 2, twice
	// Must pick first and last
	// Say middle part is [i, j]
	// Then ans = pref[i-3] + pref[j] - pref[i-2] + suf[j+3]
	// 			= pref[i-3] - pref[i-2] + pref[j] + suf[j+3]
	multiset<int> m;
	for (int j = 3; j < n; j += 2)
		if (j+3 < n)
			m.insert(pref[j] + suf[j+3]);
	for (int i = 3; i+3 < n; i += 2) {
		if (m.empty()) break;
		m.erase(m.find(pref[i] + suf[i+3]));
		if (m.empty()) break;
		int x = pref[i-3] - pref[i-2];
		x += *m.rbegin();
		ans = max(ans, x);
	}
	cout << ans;

}
// 1 2 3 4 5 6 7 8 9
// 1 2 3 4 5 6