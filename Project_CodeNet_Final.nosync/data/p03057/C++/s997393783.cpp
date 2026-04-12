#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int N = 2e5 + 100;

int n, m;
string s;

int gn(int x) {
	return x + 1 - (x % 2);
}

ll dp[N];
ll dp2[N];

void solve(int n) {
	dp[0] = 1;
	dp[1] = 2;
	for (int i = 2; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	ll ans = dp[n];
	if (n >= 4)
		ans = (ans - dp[n - 4] + MOD) % MOD;
	if (n == 2)
		ans = 3;
	if (n == 3)
		ans = 4;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	if (s[0] != 'R') {
		for (int i = 0; i < m; ++i)
			if (s[i] == 'R')
				s[i] = 'B';
			else
				s[i] = 'R';
	}
	while (!s.empty() && s.back() == 'R')
		s.pop_back();
	if (s.empty()) {
		solve(n);
		return 0;
	}
	int cur = 0;
	while (s[cur] != 'B')
		++cur;
	int l = gn(cur);
	++cur;
	while (cur < s.size()) {
		if (s[cur] == 'B')
			++cur;
		else {
			int c = 0;
			while (s[cur] == 'R')
				++cur, ++c;
			if (c % 2 == 1)
				l = min(l, c);
		}
	}
	if (n % 2 == 1) {
		cout << 0 << "\n";
		return 0;
	}
	++l;
	n /= 2;
	l /= 2;
	dp[0] = 1;
	ll sum = dp[0];
	ll sum2 = 0;
	for (int i = 1; i <= n; ++i) {
		sum2 = (sum2 + sum) % MOD;
		if (i > l) {
			sum = (sum - dp[i - l - 1] + MOD) % MOD;
			sum2 = (sum2 - dp[i - l - 1] * (l + 1) % MOD + MOD) % MOD;
		}
		dp[i] = sum;
		dp2[i] = sum2;
		sum = (sum + dp[i]) % MOD;
	}
	cout << (2 * dp2[n]) % MOD;
	return 0;
}


