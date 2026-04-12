#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	static constexpr int mod = 1e9 + 7;
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	if(s[0] == 'R') for (auto &c: s) c = 'R' + 'B' - c;
	bool flag_R = false;
	for (auto c: s) if(c == 'R') { flag_R = true; break; }
	if(flag_R) {
		int limit, i = 0, cnt = 0;
		while(i < m && s[i] == 'B') {
			++cnt;
			++i;
		}
		if(cnt & 1) limit = cnt;
		else limit = cnt + 1;
		while(i < m && s[i] == 'R') ++i;
		for(;;) {
			cnt = 0;
			while(i < m && s[i] == 'B') {
				++cnt;
				++i;
			}
			if(i == m) break;
			if(cnt & 1) limit = min(limit, cnt);
			while(i < m && s[i] == 'R') ++i;
		}
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		int sum = 1;
		for (int i = 3; i <= n; i += 2) {
			if(i - (limit + 2 + 1) > 0) sum = (sum - dp[i - (limit + 2 + 1)]) % mod;
			dp[i] = sum;
			sum = (sum + dp[i]) % mod;
		}
		if(n & 1) { cout << "0\n"; return 0; }
		int ans = 0;
		for (int i = 1; i <= n; i += 2) {
			int j = n - i;
			if(j && j <= limit) ans = ((long long) dp[i] * (j + 1) + ans) % mod;
		}
		cout << (ans + mod) % mod << endl;
	}
	else {
		vector<int> dp[2][2];
		for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) dp[a][b].resize(n, 0);
		dp[0][0][0] = dp[1][1][0] = 1;
		int t;
		for (int i = 0; i < n - 1; ++i) for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b) if(t = dp[a][b][i]) {
			dp[a][0][i + 1] = (dp[a][0][i + 1] + t) % mod;
			if(!b) dp[a][1][i + 1] = (dp[a][1][i + 1] + t) % mod;
		}
		cout << (((dp[0][0][n - 1] + dp[0][1][n - 1]) % mod + dp[1][0][n - 1]) % mod + mod) % mod << endl;
	}
	return 0;
}
