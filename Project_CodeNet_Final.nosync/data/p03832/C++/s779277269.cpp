#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
constexpr ll MOD = 1e9+7;

int pw(int base, int exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) res = (ll)base * res % MOD;
		exp >>= 1;
		base = (ll)base * base % MOD;
	}
	return res;
}

int inv(int x) { return pw(x, MOD - 2); }

int dv[1001], nCr[1001][1001], dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	for (int i = 0; i <= N; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
	}
	for (int i = 1; i <= N; ++i) dv[i] = inv(i);
	dp[A - 1][0] = 1;
	for (int i = A; i <= B; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (dp[i - 1][j]) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
				ll cnt = 1;
				for (int k = 0; k <= D && j + k * i <= N; ++k) {
					if (k >= C) dp[i][j + k * i] = (cnt * dp[i - 1][j] + dp[i][j + k * i]) % MOD;
					cnt = ((cnt * nCr[N - j - k * i][i]) % MOD) * dv[k + 1] % MOD;
				}
			}
		}
	}
	cout << dp[B][N] << '\n';
}