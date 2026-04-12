#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL dp[101][4] = {};
	UL dp2[101][4] = {};

	void Solve() {
		vector<UL> N; {
			string S; cin >> S;
			rep(i, S.size()) N.push_back(S[i] - '0');
		}
		UL K; cin >> K;
		reverse(N.begin(), N.end());
		dp[0][0] = dp2[0][0] = 1;
		rep(i, N.size()) {
			rep(j, 4) { dp2[i + 1][j] = dp2[i][j]; }
			rep(j, 3) { dp2[i + 1][j + 1] += 9 * dp2[i][j]; }
			if (N[i] == 0) {
				rep(j, 4) { dp[i + 1][j] = dp[i][j]; }
			}
			else {
				rep(j, 3) { dp[i + 1][j + 1] = dp[i][j]; }
				rep(j, 4) { dp[i + 1][j] += dp2[i][j]; }
				rep(j, 3) { dp[i + 1][j + 1] += (N[i] - 1) * dp2[i][j]; }
			}
		}
		cout << dp[N.size()][K] << endl;
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