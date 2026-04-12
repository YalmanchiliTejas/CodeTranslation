#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long M = 1e9 + 7;
	int n;
	cin >> n;
	int a[n];
	long long total = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n-1; i++) {
		total -= a[i];
		ans += ((a[i] % M) * (total % M)) % M;
	}
	ans = ans % M;
	cout << ans << '\n';
	return 0;
}
