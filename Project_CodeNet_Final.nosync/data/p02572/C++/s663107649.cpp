#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve_test() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int answer = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		answer = (answer + sum * a[i] % MOD) % MOD;

		sum = (sum + a[i]) % MOD;
	}

	cout << answer << '\n';
}

int32_t main() {
	int T; 
	// cin >> T;
	T = 1;
	while (T--)
		solve_test();

	return 0;
}
