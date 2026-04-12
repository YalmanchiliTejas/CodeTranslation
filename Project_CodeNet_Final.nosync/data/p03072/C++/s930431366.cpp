#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i=0; i<n; ++i) {
		cin >> h[i];
	}
	int sum = 1;
	for (int i=1; i<n; ++i) {
		bool see = true;
		for (int j=0; j<i; ++j) {
			if (h[j] > h[i]) {
				see = false;
				break;
			}
		}
		if (see) {
			sum += 1;
		}
	}
	cout << sum << endl;
	return 0;
}