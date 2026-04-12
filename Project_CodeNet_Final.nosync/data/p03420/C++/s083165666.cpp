#include <bits/stdc++.h>

using namespace std;

inline void Boost() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}
typedef long long int ll;
typedef long double ld;

int main() {
	Boost();

	int n, k; cin >> n >> k;

	ll ans = 0;
	for (int b = k + 1; b <= n; ++b) {
		ans += (n / b) * (b - k);
		int now = n;
		int prev = (n / b) * b;
		// cout << (n / b) * (b - k) << " " << max(0, now - prev - k + 1) << " " << now << " " << prev << endl;
		ans += max(0, now - prev - k + 1);
	}

	if (k == 0) ans -= n;
	cout << ans;
	return 0;
}