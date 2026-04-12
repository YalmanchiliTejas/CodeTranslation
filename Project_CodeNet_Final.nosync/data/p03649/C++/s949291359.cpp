#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int N;
	cin >> N;
	vector<Int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	Int ans = 0;
	while (true) {
		Int sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += a[i] / N;
		}
		if (sum == 0) { break; }

		for (int i = 0; i < N; ++i) {
			a[i] += (sum - a[i] / N) - (a[i] / N * N);
		}
		ans += sum;
	}
	cout << ans << endl;

	return 0;
}
