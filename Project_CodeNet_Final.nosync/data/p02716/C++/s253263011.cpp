#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	for (auto& x : A) cin >> x;
	if (N <= 3) {
		cout << *max_element(A.begin(), A.end()) << endl;
		return 0;
	}
	ll res = 0;
	for (int i = 1; i < N; i += 2) res += A[i];

	vector<map<int,ll>> a(N);
	a[0][1] = A[0];
	a[1][1] = A[1];
	int n = N/2;
	for (int i = 2; i < N; ++ i) {
		map<int, ll> aa;
		if (i == 2) aa[1] = A[i];
		for (int j = i-4; j <= i-2; ++ j) if (j >= 0) {
			for (auto p : a[j]) {
				int k = p.first + 1;
				if (k < i/2-2) continue;
				if (!aa.count(k)) {
					aa[k] = p.second + A[i];
					if (k == n) res = max(res, aa[k]);
				} else {
					aa[k] = max(aa[k], p.second + A[i]);
					if (k == n) res = max(res, aa[k]);
				}
			}
		}
		a[i] = aa;
	}
	cout << res << endl;
}
