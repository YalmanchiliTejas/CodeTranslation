#include <bits/stdc++.h>
using namespace std;

const int md = (int)1e9 + 7;
inline void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}
inline void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += md;
}
inline int mul(int a, int b) {
	return (int) ((long long) a * b % md);
}
int main() {
#ifdef LOCAL_DEFINE
	// freopen("data.in", "rt", stdin);
	// freopen("data.out", "w", stdout);
	auto _start = chrono::high_resolution_clock::now();
#endif

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	string s;
	int d;
	cin >> s >> d;
	int n = s.length();
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(d, vector<int>(2)));
	dp[0][0][1] = 1;
	for (int i = 0; i < n; i++) {
		int cdig = s[i] - '0';
		for (int j = 0; j < d; j++) {
			for(int dig = 0; dig <= 9; dig++) {
				add(dp[i + 1][(j + dig) % d][0], dp[i][j][0]);
			}
			for(int dig = 0; dig <= cdig; dig++) {
				add(dp[i + 1][(j + dig) % d][dig == cdig], dp[i][j][1]);
			}
		}
	}
	int ans = md - 1;
	add(ans, dp[n][0][0]);
	add(ans, dp[n][0][1]);
	cout << ans << '\n';

#ifdef LOCAL_DEFINE
	auto _end = chrono::high_resolution_clock::now();
	cerr << "elapsed time: " << chrono::duration<double, milli>(_end - _start).count() << " ms\n";
#endif
	return 0;
}