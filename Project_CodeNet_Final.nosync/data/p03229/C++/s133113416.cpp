#include "bits/stdc++.h"

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.rbegin(), A.rend());
	long long ans = 0;
	if (0 == N % 2) {
		{
			// 0 .... (N-3)/2
			for (int i = 0; i < (N - 2) / 2; ++i) {
				ans += 2 * A[i];
			}
			for (int i = (N - 2) / 2; i < (N) / 2; ++i) {
				ans += A[i];
			}
			for (int i = (N) / 2; i < (N + 2) / 2; ++i) {
				ans -= A[i];
			}
			for (int i = (N + 2) / 2; i < N; ++i) {
				ans -= 2 * A[i];
			}
		}
	}
	else {
		{
			long long ans0 = 0;
			// 0 .... (N-3)/2
			for (int i = 0; i < (N - 3) / 2; ++i) {
				ans0 += 2 * A[i];
			}
			for (int i = (N - 3) / 2; i < (N + 1) / 2; ++i) {
				ans0 += A[i];
			}
			for (int i = (N + 1) / 2; i < N; ++i) {
				ans0 -= 2 * A[i];
			}
			ans = max(ans0,ans);
		}
		{
			long long ans0 = 0;
			// 0 .... (N-3)/2
			for (int i = 0; i < (N - 1) / 2; ++i) {
				ans0 += 2 * A[i];
			}
			for (int i = (N - 1) / 2; i < (N + 3) / 2; ++i) {
				ans0 -= A[i];
			}
			for (int i = (N + 3) / 2; i < N; ++i) {
				ans0 -= 2 * A[i];
			}
			ans = max(ans0, ans);
		}
	}
	cout << ans << endl;
}
