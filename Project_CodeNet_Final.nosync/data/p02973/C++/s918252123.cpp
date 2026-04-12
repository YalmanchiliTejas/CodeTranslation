#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	const int INF = 1e9 + 10;
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	reverse(a.begin(), a.end());
	vector<int> v(N + 1, INF);
	for (int i = 0; i < N; ++i) {
		*upper_bound(v.begin(), v.end(), a[i]) = a[i];
	}
	int res = lower_bound(v.begin(), v.end(), INF) - v.begin();
	cout << res << endl;

	return 0;
}
