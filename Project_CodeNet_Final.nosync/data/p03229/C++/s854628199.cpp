#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> d(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		d[i] = a[i + 1] - a[i];
	}
	if (n % 2 == 0) {
		long long ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans += 2LL * d[i] * min(i + 1, n - i - 1);
		}
		cout << ans - d[n / 2 - 1] << endl;
	}
	else {
		long long ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			ans += 2LL * d[i] * min(i + 1, n - i - 1);
		}
		cout << ans - min(d[n / 2 - 1], d[n / 2]) << endl;
	}
	return 0;
}