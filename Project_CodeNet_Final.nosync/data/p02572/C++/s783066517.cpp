#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	constexpr Int MOD = 1e9 + 7;
	int N;
	cin >> N;
	vector<Int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	vector<Int> d(N, 0);
	for (int i = 0; i < N; ++i) {
		d[i] = a[i];
		if (i > 0) { (d[i] += d[i - 1]) %= MOD; }
	}

	Int ans = 0;
	for (int i = N - 1; i > 0; --i) {
		(ans += a[i] * d[i - 1] % MOD) %= MOD;
	}
	cout << ans % MOD << "\n";

	return 0;
}
