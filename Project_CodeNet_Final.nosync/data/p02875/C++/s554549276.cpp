/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e7 + 10, mod = 998244353;

ll fact[N], finv[N], p2[N];

ll pwr(ll x, ll e);
ll choose(int n, int k);

int main() {
	fast_cin();
	int n; cin >> n;
	fact[0] = finv[0] = p2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		p2[i] = (2 * p2[i - 1]) % mod;
		fact[i] = (i * fact[i - 1]) % mod;
		finv[i] = pwr(fact[i], mod - 2);
	}
	ll ans = pwr(3, n);
	for (int k = n / 2 + 1; k <= n; ++k) {
		ll temp = choose(n, k) * p2[n - k + 1];
		temp %= mod;
		ans += mod - temp;
		ans %= mod;
	}
	cout << ans << endl;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		e /= 2;
		x = (x * x) % mod;
	}
	return res;
}

ll choose(int n, int k) {
	ll ans = fact[n] * finv[k];
	ans %= mod;
	ans *= finv[n - k];
	return ans % mod;
}