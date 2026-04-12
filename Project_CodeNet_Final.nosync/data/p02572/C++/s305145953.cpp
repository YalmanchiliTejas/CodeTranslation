#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int64_t running = 0, ans = 0;
	for (int i = 0; i < N; ++i) {
		int64_t e;
		cin >> e;
		ans += (e*running);
		ans %= mod;
		running = (running+e)%mod;
	}
	// vector<int64_t> A(N), pre(N), suf(N);
	// for (int64_t& e : A) cin >> e;
	// pre[0] = A[0];
	// for (int i = 1; i < N; ++i) pre[i] = (pre[i-1]+A[i])%mod;
	// int64_t ans = 0;
	// for (int i = 1; i < N; ++i) {
	// 	cout << i << " " << pre[i-1] << endl;
	// 	ans += (A[i]*pre[i-1])%mod;
	// }
	cout << ans << endl;
	// suf[N-1] = A[N-1];
	// for (int i = N-2; i >= 0; --i) suf[i] = (suf[i+1]+A[i])%mod;
}