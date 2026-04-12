#include <iostream>
#include <algorithm>
#include <string>
#define int long long
using namespace std;
signed main() {
	int n, a[114514], ans = 0; cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2 - 1; i++)ans += a[n - 1 - i] * 2; ans += a[n / 2];
		for (int i = 0; i < n / 2 - 1; i++)ans -= a[i] * 2; ans -= a[n / 2 - 1];
	}
	else {
		for (int i = 0; i < n / 2 - 1; i++)ans += a[n - 1 - i] * 2;
		for (int i = 0; i < n / 2 - 1; i++)ans -= a[i] * 2;
		int p = a[n / 2 - 1], q = a[n / 2], r = a[n / 2 + 1];
		ans += max(-2 * p + q + r, -p - q + 2 * r);
	}
	cout << ans << endl;
}