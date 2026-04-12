#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

const int MX = 1200;
const ll MOD = 1e9 + 7;

ll fc[MX];
ll bfc[MX];
ll dp[MX];
ll dp2[MX];

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while(!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD;
		--b;
	}
	return ans;
}

void init() {
	fc[0] = 1;
	for (int i = 1; i < MX; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	for (int i = 0; i < MX; ++i)
		bfc[i] = pw(fc[i], MOD - 2);
}

ll cnk(int n, int k) {
	if (n < k)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int n;
int a, b, c, d;
int main() {
	init();
	cin >> n >> a >> b >> c >> d;
	dp[0] = 1;
	for (int i = a; i <= b; ++i) {
		for (int j = 0; j <= n; ++j)
			dp2[j] = dp[j];
		ll bf = 1;
		ll b1 = bfc[i];
		for (int k = 1; k < c; ++k)
			bf = (bf * b1) % MOD;
		for (int k = c; k <= d; ++k) {
			bf = (bf * b1) % MOD;
			ll bk = (bf * bfc[k]) % MOD;
			int cnt = k * i;
			if (cnt > n)
				break;
			for (int j = 0; j + cnt <= n; ++j)
				dp2[j + cnt] = (dp2[j + cnt] + dp[j] * cnk(n - j, cnt) % MOD * fc[cnt] % MOD * bk) % MOD;
		}
		for (int j = 0; j <= n; ++j)
			dp[j] = dp2[j];
	}
	cout << dp[n] << "\n";
	return 0;
}


