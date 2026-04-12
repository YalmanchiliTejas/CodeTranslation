#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> x;
		int l = 0, r = a.size() - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (a[m] < x) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		if (l < a.size()) {
			a[l] = x;
		} else {
			a.push_back(x);
		}
	}
	cout << a.size() << endl;
	return 0;
}