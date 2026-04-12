#include <bits/stdc++.h>
#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 44;
const int mod = 1e9 + 7;
const long long INF = 1e18;
const int inf = 1e9 + 44;

string s;

int d;

long long dp[10100][105];

long long go (int pos = 0, bool sp = 1, int m = 0) {
	if (pos == (int) s.size()) return !m;
	int l = 0, r = 9;
	if (sp) {
		long long res = 0;
		r = s[pos] - '0';
		while (l < r) {
			res += go (pos + 1, 0, (m + l) % d);
			res %= mod;
			++l;
		}
		res += go (pos + 1, 1, (m + r) % d);
		res %= mod;
		return res;
	}
	long long &res = dp[s.size() - pos][m];
	if (res != -1) return res;
	res = 0;
	while (l <= r) {
		res += go (pos + 1, 0, (m + l) % d);
		res %= mod;
		++l;
	}
	return res;
}

int main () {
	boost;
	for (int i = 0 ; i <= 10099 ; ++ i) {
		for (int j = 0 ; j < 104 ; ++ j) {
			dp[i][j] = -1;
		}
	}
	cin >> s >> d;
	cout << (go() - 1 + mod) % mod;
}