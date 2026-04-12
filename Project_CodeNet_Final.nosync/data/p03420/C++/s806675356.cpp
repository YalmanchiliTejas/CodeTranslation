#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << n * n << endl;
		return 0;
	}
	int64_t ans = 0;
	for (int64_t b = k + 1; b <= n; b++) {
		ans += n / b * (b - k);
		if (k <= n % b) {
			ans += n % b - k + 1;
		}
	}
	cout << ans << endl;
	return 0;
}