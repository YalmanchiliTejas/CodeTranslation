#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n, a[N];
vector<int> res;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = n - 1; i >= 0; --i) {
		int pos = -1;
		for (int j = 0; j < n; ++j) {
			if (a[j] == i) pos = j;
		}
		for (int j = 0; j <= pos; ++j) res.push_back(1);
		for (int j = pos + 1; j < n; ++j) {
			if (a[j] < a[j - 1]) {
				res.push_back(n - 1), swap(a[j], a[j - 1]);
			}
			res.push_back(1);
		}
		// for (int j = 0; j < n; ++j) cout << a[j] << ' '; cout << '\n';
	}
	cout << res.size() << '\n';
	for (auto i : res) cout << i << '\n';
}