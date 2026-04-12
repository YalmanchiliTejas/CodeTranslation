#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a = (1LL * a + b) % MOD;
}

int product(int a, int b) {
	return 1LL * a * b % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0, prefix = 0;
	for (int i = 0; i < n; i++) {
		add(ans, product(prefix, a[i]));
		add(prefix, a[i]);
	}
	cout << ans;
}

