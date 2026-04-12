#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

#define int long long

using namespace std;

signed main() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int a = k + 1; a <= n; a++) {
		ans += (a - k) * (n / a);
		int c = n % a;
		ans += max((int)0, c - k + 1);
		// cout << a << ' ' << ans << '\n';
	}
	if (k == 0) {
		ans -= n;
	}
	cout << ans << '\n';
}