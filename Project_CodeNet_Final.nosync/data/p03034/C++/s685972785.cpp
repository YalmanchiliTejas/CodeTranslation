#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<LL> S(N); rep(i, N) cin >> S[i];
		LL ans = 0;
		N--;
		for (UL D = 1; D < N; D++) {
			UL mx = (N + 1) / D;
			if (N % D == 0) mx = (N / D + 1) / 2;
			LL sum = 0;
			for (UL T = 1; T < mx; T++) {
				sum += S[D * T];
				sum += S[N - D * T];
				ans = max(ans, sum);
				//cout << "(D, T) = (" << D << ", " << T << ") : ";
				//cout << sum << endl;
			}
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