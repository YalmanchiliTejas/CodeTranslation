#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int INF = (int)1 << 60;
	int res = -INF;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	if (N % 2 == 0) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				sum += A[i];
			}
		}
		int x = 0;
		int mx = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (i % 2 == 0) {
				x -= A[i];
				mx = max(mx, x);
			} else {
				x += A[i];
			}
		}
		res = sum + mx;
	} else {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				sum += A[i];
			}
		}
		int x = 0;
		int mx = -INF;
		int mn = 0;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				x -= A[i];
				mx = max(mx, x - mn);
			} else {
				x += A[i];
				mn = min(mn, x);
			}
		}
		res = sum + mx;
	}
	cout << res << endl;
}