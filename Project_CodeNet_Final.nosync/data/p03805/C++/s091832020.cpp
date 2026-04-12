#include <bits/stdc++.h>
using namespace std;

bool isConnected(int s, int t, vector<pair<int, int>> a) {
	for (int i = 0; i < a.size(); ++i) {
		if ((s == a[i].first and t == a[i].second) or (s == a[i].second and t == a[i].first)) {
			return true;
		}
	}
	return false;
}

bool isPath(vector<int> n, vector<pair<int, int>> p) {
	for (int i = 0; i < n.size() - 1; ++i) {
		if (!isConnected(n[i], n[i + 1], p)) {
			return false;
		}
	}
	return true;
}

signed main() {
	int n, m, cnt = 0;
	cin >> n >> m;

	vector<pair<int, int>> p(m);
	vector<int> num;

	for (int i = 1; i <= n; ++i) {
		num.push_back(i);
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		p[i] = make_pair(a, b);
	}

	do {
		if (isPath(num, p)) cnt++;
	} while (next_permutation(num.begin() + 1, num.end()));


	cout << cnt << endl;
}

