#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MOD = 1e9+7;

int main() {
	int n;

	cin >> n;

	vector <ll> a(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector <ll> b(n+1, 0);

	for (int i = n-1; i >= 0; i--) {
		b[i] = b[i+1] + a[i];
		b[i] = b[i] % MOD;
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ans = ans + (a[i]*b[i+1]);
		ans = ans % MOD;
	}

	cout << ans << "\n";

	return 0;
}