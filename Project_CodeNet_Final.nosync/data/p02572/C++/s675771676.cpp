#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 2e5;

long long a[MAX_N + 1], ps[MAX_N + 1], ans;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		ps[i] = a[i] + (i > 0? ps[i - 1] : 0);
		ps[i] %= MOD;
		ans += (a[i] * (i > 0? ps[i - 1] : 0)) % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
