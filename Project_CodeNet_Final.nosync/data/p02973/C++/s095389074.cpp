#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <int> dp, a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=n-1; i>=0; i--) {
		auto l = upper_bound(dp.begin(), dp.end(), a[i]);
		if (l == dp.end()) {
			dp.push_back(a[i]);
		} else {
			dp[l-dp.begin()] = a[i];
		}
	}
	cout << dp.size();
	return 0;
}
