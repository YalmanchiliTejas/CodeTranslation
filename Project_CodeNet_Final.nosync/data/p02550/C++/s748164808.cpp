#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int N, X, M;
	cin >> N >> X >> M;

	map<Int, Int> mp;
	Int cnt = 1;
	Int A = X;
	vector<Int> sum(1000000, 0);
	Int ans = 0;
	while (cnt <= N) {
		sum[cnt] += sum[cnt - 1];
		if (mp.count(A) == 0) {
			mp[A] = cnt;
			sum[cnt++] += A;
			A = A * A % M;
			continue;
		}

		Int idx = mp[A];
		sum[cnt] += A;
		A = A * A % M;
		
		Int S = sum[cnt] - sum[idx];
		Int n = cnt - idx;
		ans = sum[idx] + (N - idx) / n * S;
		for (Int i = 0; i < (N - idx) % n; ++i) {
			ans += A;
			A = A * A % M;
		}
		break;
	}
	if (cnt > N) { ans = sum[N]; }
	cout << ans << "\n";

	return 0;
}
