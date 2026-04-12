#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for (int b = k + 1; b <= n; b++) {
		ans += n / b * (b - k);
		ans += max(0, n % b - k + 1);
		ans -= k == 0 ? 1 : 0;
	}
	cout << ans << endl;
	return 0;	
}