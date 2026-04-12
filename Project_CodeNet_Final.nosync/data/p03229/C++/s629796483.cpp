#include <iostream>
#include <algorithm>
using namespace std;

long long n, a[100009], ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		ans += 2LL * min(1LL * i + 1LL, n - 1LL - i)*(a[i + 1] - a[i]);
	}
	if (n % 2 == 0) ans -= (a[n / 2] - a[n / 2 - 1]);
	else {
		ans -= min(a[n / 2] - a[n / 2 - 1], a[n / 2 + 1] - a[n / 2]);
	}
	cout << ans << endl;
	return 0;
}