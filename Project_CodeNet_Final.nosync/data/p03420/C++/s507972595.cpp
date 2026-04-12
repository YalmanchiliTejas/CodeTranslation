#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long n, k, ans = 0; cin >> n >> k;
	for (long long b = k + 1, m; b <= n; b++) {
		m = n / b;
		ans += (b - k) * m + max(n - (b * m + k - 1), 0LL) - (k == 0 ? 1 : 0);
	}
	cout << ans << endl;

	return 0;
}