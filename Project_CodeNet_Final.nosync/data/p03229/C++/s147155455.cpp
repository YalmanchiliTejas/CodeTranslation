#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(false);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	ll res = a[n-1] - a[0];
	for (int i = 1; i < n/2; ++i) {
		res += a[n-i] - a[i];
		res += a[n-i-1] - a[i-1];
	}
	if(n & 1)
		res += max(a[n/2+1] - a[n/2], a[n/2] - a[n/2-1]);
	cout << res << '\n';
	return 0;
}