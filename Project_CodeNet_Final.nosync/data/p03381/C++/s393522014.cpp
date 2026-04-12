#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	auto b(a);
	sort(b.begin(), b.end());
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[b[i]] = i;
	}
	for (auto &i : a) {
		cout << (2 * m[i] < n ? b[n / 2] : b[n / 2 - 1]) << endl;
	}
	return 0;
}