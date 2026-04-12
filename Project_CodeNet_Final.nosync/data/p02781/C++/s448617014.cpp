#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
#define int ll


const int N = 1000;
const int K = 10;
string s;
int k, d[N], dp[N][K][2];

signed main() {
#ifdef LC
    assert(freopen("input.txt", "r", stdin));
#endif
    ios::sync_with_stdio(0), cin.tie(0);
	
	cin >> s >> k;
	for (int i = 0; i < (int)s.size(); ++i) {
		d[N - 1 - i] = s[(int)s.size() - 1 - i] - '0';
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j + 1 < K; ++j) {
			for (int c = 0; c < 10; ++c) {
				if (c <= d[i + 1]) {
					dp[i + 1][j + (c != 0)][c < d[i + 1]] += dp[i][j][0];
				}
				dp[i + 1][j + (c != 0)][1] += dp[i][j][1];
			}
		}
	}
	int x = dp[N - 1][k][0], y = dp[N - 1][k][1];
	cerr << x << " " << y << endl;
	cout << x + y << endl;
	return 0;
}
