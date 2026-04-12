#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#define rep(i,n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
typedef pair<int, int> P;
int s[100000];
map<P, ll> dp;
int main() {
	int N;
	cin >> N;
	rep(i, N) cin >> s[i];
	ll ans = 0;
	for (int C = 1; C < N - 1; C++) {
		dp[P(C, 0)] = 0;
		set<int> S;
		S.insert(0);
		S.insert(N - 1);
		for (int k = 1; (k + 1)*C < N - 1; k++) {
			if ((N - 1) - k * C == k * C || S.count(k*C) > 0 || S.count((N - 1) - k * C) > 0) break;
			S.insert(k*C);
			S.insert((N - 1) - k * C);
			dp[P(C, k)] = dp[P(C, k - 1)] + s[k*C] + s[(N - 1) - k * C];
			ans = max(ans, dp[P(C, k)]);
		}
	}
	cout << ans << endl;
}