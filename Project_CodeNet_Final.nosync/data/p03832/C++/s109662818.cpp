#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define MP(a,b) make_pair(a,b)
typedef long long LL;
typedef pair<int, int> PI;
typedef vector<int> VI;
typedef pair<double, int> P;
const LL MOD = 1000000007LL;
LL dp[1010][1001];
LL fact[1001];
LL inv[1001];
LL inv_fact[1001];
LL mod_pow(LL a, LL n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		LL tmp = mod_pow(a, n / 2);
		return (tmp*tmp) % MOD;
	}
	else {
		return (a*mod_pow(a, n - 1)) % MOD;
	}
}
LL comb(LL n, LL k) {
	if (k > n) return 0;
	LL ans = fact[n];
	ans = (ans*inv_fact[k]) % MOD;
	ans = (ans*inv_fact[n - k]) % MOD;
	return ans;
}
int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	fact[0] = 1;
	inv_fact[0] = 1;
	REP(i, 1, N + 1) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = mod_pow(i, MOD - 2);
		inv_fact[i] = (inv_fact[i - 1] * inv[i]) % MOD;
	}
	dp[A][N] = 1;
	REP(i, A, B + 1) {
		rep(j, N + 1) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
			if (j < i*C) continue;
			LL tmp = inv_fact[C - 1];
			for (int k = 0; k <= C-2; k++) {
				tmp = (tmp*comb(j - i*k, i)) % MOD;
			}
			for (int k = C; k <= D&&i*k <= j; k++) {
				tmp = (tmp*comb(j - i*(k - 1), i)) % MOD;
				tmp = (tmp*inv[k]) % MOD;
				LL add = (dp[i][j] * tmp) % MOD;
				dp[i + 1][j - i*k] = (dp[i + 1][j - i*k] + add) % MOD;
			}
		}
	}
	cout << dp[B + 1][0] << endl;
}