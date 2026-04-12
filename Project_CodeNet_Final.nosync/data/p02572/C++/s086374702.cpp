#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];

	vector<ll> B(N);
	B[N-1] = A[N-1];
	for(int i = N-2; i >= 0; i--)
		B[i] = (B[i+1] + A[i]) % 1000000007;

	ll ans = 0;
	for(int i = 0; i < N-1; i++) {
		ans += A[i] * B[i+1] % 1000000007;
		ans %= 1000000007;
	}

	cout << ans << endl;
	return 0;
}