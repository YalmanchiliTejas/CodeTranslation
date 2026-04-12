#include <bits/stdc++.h>
using namespace std;

signed main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for (auto &e : h) {
		cin >> e;
	}

	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		bool flag = true;
		for (int j = 0; j < i; ++j) {
			if (h[i] < h[j]) flag = false;
		}
		if (flag) cnt++;
	}

	cout << cnt << endl;
}

