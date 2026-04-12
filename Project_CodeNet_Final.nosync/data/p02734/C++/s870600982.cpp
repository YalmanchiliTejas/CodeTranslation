#include <cstdio>
#include <vector>
using namespace std;

int read_int() {
	int x;
	scanf("%d", &x);
	return x;
}

typedef long long i64;
const i64 MOD = 998244353;

int main() {

	const int N = read_int();
	const int S = read_int();
	vector<int> AS(N);
	for(int i = 0; i < N; i++) {
		AS[i] = read_int();
	}

	vector<vector<i64>> dp(N * 2);
	for(auto& d : dp) {
		d.resize(S + 1, 0);
	}

	if(AS[0] <= S) {
		dp[0][AS[0]] = 1;
	}

	for(int pos = 1; pos < N; pos++) {
		const int a = AS[pos];
		for(int i = 1; i <= S - a; i++) {
			dp[pos][i + a] = (dp[pos - 1][i] + dp[pos - 1 + N][i]) % MOD;
		}
		for(int i = 1; i <= S; i++) {
			dp[pos + N][i] = (dp[pos - 1][i] + dp[pos - 1 + N][i]) % MOD;
		}
		if(a <= S) {
			dp[pos][a] = pos + 1;
		}
	}

	i64 ans = 0;
	for(int pos = 0; pos < N; pos++) {
		ans = (ans + dp[pos][S] * (N - pos)) % MOD;
	}

	printf("%lld\n", ans);

	return 0;
}
