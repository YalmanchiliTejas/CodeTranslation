#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e9, MOD = 1e9 + 7, MOD2 = 1e6 + 3;

string s;

ll dp[100][2], last[100];

ll p[100], sz[100], n;

vector < pair <ll, ll> > v;

ll qpow (ll a, ll b) {
	ll s = 1;

	while (b) {
		if (b & 1) s = s * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}

	return s;
}

ll find (ll x) {
	if (x == p[x]) return x;
	return p[x] = find (p[x]);
}

void actualize (ll x, ll y) {
	dp[x][0] = dp[x][0] * qpow (2, last[x] - y) % MOD;
	last[x] = y;
}

void unite (ll a, ll b) {
	a = find (a);
	b = find (b);

	if (a == b) return;

	if (sz[a] < sz[b]) swap (a, b);

	actualize (a, min (last[a], last[b]));
	actualize (b, min (last[a], last[b]));

	dp[a][1] = (dp[a][1] * (2 * dp[b][0] % MOD + dp[b][1]) % MOD) % MOD + 2 * dp[a][0] * (dp[b][0] + dp[b][1]) % MOD;
	dp[a][0] = dp[a][0] * dp[b][0] % MOD;

	p[b] = a;

	sz[a] += sz[b];
}

int main () {
	cin >> n;

	for (ll i = 0; i < n; i++) {
		ll h;

		scanf ("%lld", &h);

		last[i] = h;

		v.emplace_back (h, i);

		dp[i][0] = 1;
		dp[i][1] = 0;

		sz[i] = 1;
		p[i] = i;
	}

	sort (v.begin(), v.end());
	reverse (v.begin(), v.end());

	for (auto a : v) {

		if (a.second != n - 1 && last[a.second + 1] >= last[a.second]) {
			unite (a.second, a.second + 1);
		}
		if (a.second && last[a.second - 1] >= last[a.second]) {
			unite (a.second - 1, a.second);
		}
	}

	actualize (find (0), 1);

	cout << (2 * dp[find (0)][0] + dp[find (0)][1]) % MOD;
}