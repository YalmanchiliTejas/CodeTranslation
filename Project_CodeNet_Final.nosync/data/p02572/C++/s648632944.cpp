#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int MOD = 1e9 + 7;

int n;

int main() {

	FAST;

	cin >> n;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector <int> suff(n + 1);
	suff[n] = a[n];
	for (int i = n - 1; i >= 1; i --) {
		suff[i] = 1LL * (suff[i + 1] + a[i]) % MOD;
	}
	int ans = 0;
	for (int i = 1; i < n; i ++) {
		int plus = 1LL * a[i] * suff[i + 1] % MOD;
		ans = 1LL * (ans + plus) % MOD;
	}
	cout << ans << '\n';
	return 0;
}