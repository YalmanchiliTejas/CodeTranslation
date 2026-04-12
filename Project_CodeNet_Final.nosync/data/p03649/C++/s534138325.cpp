#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool judge(vector<ll>& a, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] >= n) return false;
	}
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	while (!judge(a, n)) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i] / n;
		}
		for (int i = 0; i < n; i++) {
			a[i] += sum - a[i] / n - (a[i] / n) * n;
		}
		ans += sum;
	}
	cout << ans << endl;	
	return 0;
}