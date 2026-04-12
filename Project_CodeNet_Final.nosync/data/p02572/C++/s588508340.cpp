#include <bits/stdc++.h>
using namespace std;

#define MorsheD ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	// ===================
	MorsheD;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	// ===================

	int n;
	cin >> n;

	ll ara[n], pre[n] = {};
	for (int i = 0; i < n; ++i) {
		cin >> ara[i];

		if (i) {
			pre[i] = ara[i] + pre[i - 1];
		} else {
			pre[i] = ara[i];
		}
	}

	ll sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum += (((pre[n - 1] - pre[i]) % MOD) * (ara[i] % MOD)) % MOD;
		sum %= MOD;
	}

	cout << sum % MOD << '\n';

	return 0;
}