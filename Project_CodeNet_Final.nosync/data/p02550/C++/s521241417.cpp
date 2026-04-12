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
	Ans[0] = 0;
	Ans[1] = Ans[0] + X;
	for (long long i = 1; i < N; ++i) {
		X *= X;
		X %= M;
		Ans[i + 1] = Ans[i] + X;
		if (s.count(X)) {
			long long ans = 0;
			long long memo = N - i;
			memo %= (i - p[X]);
			ans += Ans[p[X]];
			ans += (Ans[i + 1] - Ans[p[X] + 1])*((N - p[X]) / (i - p[X]));
			ans += (Ans[p[X] + memo] - Ans[p[X]]);
			cout << ans << endl;
			return 0;
		}
		s.insert(X);
		p[X] = i;
	}
	cout << Ans[N] << endl;
	return 0;
}