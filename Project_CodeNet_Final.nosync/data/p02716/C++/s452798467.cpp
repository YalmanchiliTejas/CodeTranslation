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

	LL dp[200003][3];

	void Solve() {
		UL N; cin >> N;
		vector<LL> A(N); rep(i, N) cin >> A[i];
		rep(j, 3) dp[0][j] = dp[1][j] = 0;
		rep(i, N) {
			dp[i + 2][0] = dp[i][0] + A[i];
			dp[i + 2][1] = max(dp[i + 1][0], dp[i][1] + A[i]);
			dp[i + 2][2] = max(dp[i + 1][1], dp[i][2] + A[i]);
		}
		if (N % 2) cout << dp[N + 1][2] << endl;
		else cout << dp[N + 1][1] << endl;
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
