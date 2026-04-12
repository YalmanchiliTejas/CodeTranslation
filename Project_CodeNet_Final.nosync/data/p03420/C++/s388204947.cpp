#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	ll ans = 0;
	int n, k;
	cin >> n >> k;
	for (int b = k + 1; b <= n; ++b) {
		int l = k;
		int r = b;
		for (; l <= n; l += b, r += b) {
			if (l != 0)
				ans += min(n + 1, r) - l;
			else
				ans += max(0, min(n + 1, r) - (l + 1));
		}
	}
	cout << ans << "\n";
	return 0;
}


