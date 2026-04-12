#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

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

string s;
int a[12000];
int d;
ll dp[2][120];
ll dp2[2][120];
const ll MOD = 1e9 + 7;

void add(ll &a, ll b) {
	a = (a + b) % MOD;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s;
	reverse(ALL(s));
	for (int i = 0; i < s.size(); ++i)
		a[i] = s[i] - '0';
	int n = s.size();
	++a[0];
	int now = 0;
	while (a[now] == 10)
		a[now] = 0, ++now, ++a[now];
	n = max(n, now + 1);
	cin >> d;
	dp[0][0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		memset(dp2, 0, sizeof(dp2));
		for (int fl = 0; fl < 2; ++fl)
			for (int j = 0; j < d; ++j)
				for (int k = 0; k < 10; ++k) {
					if (!fl && k > a[i])
						continue;
					int fl1 = fl || (k < a[i]);
					add(dp2[fl1][(j + k) % d], dp[fl][j]);
				}
		memcpy(dp, dp2, sizeof(dp));
	}
	cout << (dp[1][0] + MOD - 1) % MOD << "\n";
	return 0;
}


