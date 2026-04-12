#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
int n;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int pref = 0;
	int ans = 0;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		ans = add(ans, mul(x, pref));
		pref = add(pref, x);
	}

	cout << ans << '\n';

	return 0;
}
