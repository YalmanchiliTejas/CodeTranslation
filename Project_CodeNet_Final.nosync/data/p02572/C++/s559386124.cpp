#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	vector<int> a(n, 0);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sum %= mod;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		sum -= a[i];
		if (sum < 0) {
			sum += mod;
		}
		ans += (a[i] * sum) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
