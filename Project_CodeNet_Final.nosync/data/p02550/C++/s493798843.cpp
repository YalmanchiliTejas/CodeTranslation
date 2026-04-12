#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, X, M;
	cin >> N >> X >> M;
	set<long long>s;
	map<long long, long long>p;
	vector<long long>Ans(M + 10);
	s.insert(X);
	p[X] = 0;
	long long ans = X;
	Ans[0] = ans;
	for (long long i = 1; i < N; ++i) {
		X *= X;
		X %= M;
		ans += X;
		Ans[i] = ans;
		if (s.count(X)) {
			ans = 0;
			long long memo = N - i;
			memo %= (i - p[X]);
			if (0 != p[X]) {
				ans += Ans[p[X] - 1];
			}
			ans += (Ans[i] - Ans[p[X]])*((N - p[X]) / (i - p[X]));
			if (0 != p[X]) {
				ans += (Ans[p[X] + memo - 1] - Ans[p[X] - 1]);
			}
			else {
				if (0 != memo) {
					ans += Ans[p[X] + memo - 1];
				}
			}
			cout << ans << endl;
			return 0;
		}
		s.insert(X);
		p[X] = i;
	}
	cout << ans << endl;
	return 0;
}