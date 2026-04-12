#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	ll tot = 0;
	while (true) {
		auto ma = max_element(A.begin(), A.end());
		if (*ma < N) break;
		ll q = *ma / N;
		*ma -= q * (N+1);
		for (int i = 0; i < N; i++) {
			A[i] += q;
		}
		assert(0 <= *ma && *ma < N);
		tot += q;
	}
	cout << tot << '\n';

	return 0;
}
