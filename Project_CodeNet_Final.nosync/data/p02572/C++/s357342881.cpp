#include <bits/stdc++.h>

using namespace std;

void fastio() {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);
}

using LL = long long;
using LD = long double;

const LL MOD = 1e9+7;
const LL INF = LLONG_MAX;
const LL N = 1e6+1;

#define F first
#define S second

int main() {
	fastio();
	
	LL n;
	cin >> n;

	vector<LL> a(n);

	for (auto &e : a) {
		cin >> e;
	}

	LL tot = accumulate(a.begin(), a.end(), 0LL);
	LL ans = 0;
	tot %= MOD;
	for (LL i = 0; i < n; ++i) {
		tot  = ((tot - a[i])%MOD + MOD) % MOD;
		ans = (ans + a[i]*tot) % MOD;
	}
	cout << ans << "\n";
}