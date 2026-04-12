#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> a(n, 0LL);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long ans = 0;
	while (1) {
		sort(a.begin(), a.end(), greater<long long>());
		if (a[0] < n) {
			break;
		}

		long long ops = a[0] / n;
		a[0] %= n;
		ans += ops;

		for (int i = 1; i < n; i++) {
			a[i] += ops;
		}
	}
	cout << ans << endl;
	return 0;
}
