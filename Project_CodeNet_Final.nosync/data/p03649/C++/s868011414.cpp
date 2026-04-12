#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
vector<int> A;
bool check(int k) {
	if (k <= 0) return false;
	int p = 0;
	for (int i = 0; i < N; i++) {
		if ((A[i] + k) % (N + 1) == N) {
			return false;
		}
		p += (A[i] + k) / (N + 1);
	}
	return (p == k);
}
signed main() {
	cin >> N;
	A.resize(N);
	int sum = 0;
	int mx = -1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
		mx = max(mx, A[i]);
	}
	if (mx < N) {
		cout << 0 << endl;
		return 0;
	}
	int res = -1;
	int x;
	for (int i = 0; i <= 49 * N; i++) {
		x = sum - i;
		if (check(x)) {
			res = x;
		}
	}
	cout << res << endl;
	return 0;
}