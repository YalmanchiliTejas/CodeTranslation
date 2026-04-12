#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int nm = 2e5, mod = 1e9 + 7;
int n, a[nm], c[nm + 1];
ll ans = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		c[i + 1] = (c[i] + a[i]) % mod;
	}

	for (int i = 1; i < n; ++i) {
		ans = ((ll) a[i] * c[i] + ans) % mod;
	}
	cout << ans << endl;
}
