#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


const ll MOD = 998244353;
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}


int n;
const int N = 1e7 + 10;

ll fc[N];
ll bfc[N];

ll cnk(int n, int k) {
    return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
    fc[0] = 1;
    for (int i = 1; i < N; ++i) {
        fc[i] = (fc[i - 1] * i) % MOD;
    }
    bfc[N - 1] = pw(fc[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;
    }

    cin >> n;
    ll ans = pw(3, n);
    for (int i = n / 2 + 1; i <= n; ++i) {
        ans = (ans - cnk(n, i) * pw(2, 1 + n - i) % MOD + 2 * MOD) % MOD;
    }
    cout << ans << "\n";
	return 0;
}


