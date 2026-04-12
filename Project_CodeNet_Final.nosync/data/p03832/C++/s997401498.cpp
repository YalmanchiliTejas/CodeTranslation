#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2003, MOD = 1e9 + 7;
int n, a, b, c, d, dp[N][N], C[N][N];
int fact[N][N], rev[N][N];

void add(int & x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int bp(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1)
			res = (ll)res * x % MOD;
		x = (ll)x * x % MOD;
		y /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	for (int i = 0; i < N; i++) fact[0][i] = 1;
	for (int i = 1; i < N; i++) {
		fact[i][0] = 1;
		int F = (ll)fact[i - 1][1] * i % MOD;
		for (int j = 1; j < N; j++) {
			fact[i][j] = (ll)fact[i][j - 1] * F % MOD;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rev[i][j] = bp(fact[i][j], MOD - 2);
		}
	}
	C[0][0] = 1;
	for (int i = 1; i < N; i++) {
		C[i][0] = 1;
		for (int j = 1; j < N; j++) {
			C[i][j] = C[i - 1][j];
			add(C[i][j], C[i - 1][j - 1]);
		}
	}
	cin >> n >> a >> b >> c >> d;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i - 1][j];
			if (a <= i && i <= b) {
				for (int k = c; k <= d; k++) {
					if (j - k * i < 0) break;
					int t = (ll)dp[i - 1][j - k * i] * C[n - j + k * i][k * i] % MOD;
					t = (ll)t * rev[k][1] % MOD;
					add(dp[i][j], ((ll)t * fact[k * i][1] % MOD) * rev[i][k] % MOD);
				}
			}
		}
	}
	cout << dp[n][n];
}
