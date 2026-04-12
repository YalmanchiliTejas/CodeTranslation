#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

ll dp[3001][6001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, S;
	cin >> N >> S;
	int A[3000];
	rep(i, N) cin >> A[i];

	const int mod = 998244353;
	ll kotae = 0;
	rep(i, N) {
		if (S - A[i] > 0) kotae += dp[i][S - A[i]] * (N - i) % mod;
		if (S == A[i]) kotae += (i + 1) * (N - i);

		dp[i + 1][A[i]] += (dp[i + 1][A[i]] + i + 1) % mod;
		rep1(j, S - 1) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
			dp[i + 1][j + A[i]] = (dp[i + 1][j + A[i]] + dp[i][j]) % mod;
		}
	}


	co(kotae% mod);



	Would you please return 0;
}