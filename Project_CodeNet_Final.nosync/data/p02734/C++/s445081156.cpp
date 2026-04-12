#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {

	UL A[3000];
	ULL dp[3001] = {};
	ULL dp2[3001] = {};

	static const ULL M = 998244353;

	void Solve() {
		UL N, S; cin >> N >> S;
		rep(i, N) cin >> A[i];
		dp[0] = dp2[0] = 1;
		ULL ans = 0;
		rep(i, N) {
			for (UL s = A[i]; s <= S; s++) {
				dp2[s] += dp[s - A[i]];
			}
			dp2[0]++;
			rep(i, S + 1) dp2[i] %= M;
			rep(i, S + 1) dp[i] = dp2[i];
			ans += dp[S]; ans %= M;
		}
		cout << ans << endl;
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
