#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

const llong inf = 1100100100100100ll;
const llong mod = 1e9+7;

llong mpow(llong n, llong m) {
	if (n == 1)
		return m;

	llong ret = mpow(n/2, m);
	ret = ret * ret % mod;
	if (n&1)
		ret = ret*m%mod;

	return ret;
}

llong ncr(llong n, llong r) {
	llong ret = 1;
	for (int i = 1; i <= r; i++) {
		ret = ret * (n-i+1) % mod;
		ret = ret * mpow(mod-2, i) % mod;
	}

	return ret;
}

int main() {
	llong N, M, K;
	cin >> N >> M >> K;

	llong ans = 0;
	for (int i = 1; i <= N-1; i++) {
		ans = (ans + i * (N-i)*M*M)%mod;
	}
	for (int i = 1; i <= M-1; i++) {
		ans = (ans + i * (M-i)*N*N)%mod;
	}

	cout << ans * ncr(N*M-2, K-2) % mod << endl;

	return 0;
}