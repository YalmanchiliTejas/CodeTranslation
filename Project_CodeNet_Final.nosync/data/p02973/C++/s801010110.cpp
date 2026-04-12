#include <bits/stdc++.h>
using namespace std;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	long N;
	cin >> N;

	long long A;
	multiset<long> m;
	for (long i = 0; i < N; i++) {
		cin >> A;

		auto it = m.lower_bound(A);
		if (it != m.begin()) {
			m.erase(prev(it));
		}

		m.insert(A);
	}

	cout << m.size() << endl;

	return 0;
}
