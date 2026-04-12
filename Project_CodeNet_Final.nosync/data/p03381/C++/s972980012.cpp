#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> x(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	auto sorted = x;
	sort(sorted.begin(), sorted.end());

	int med1 = sorted[n/2 - 1];
	int med2 = sorted[n/2];

	int ans = 0;
	for (auto xx: x) {

		if (med1 == med2) {
			ans = med1;
		} else if (xx <= med1) {
			ans = med2;
		} else {
			ans = med1;
		}

		cout << ans << endl;
	}

	return 0;
}
