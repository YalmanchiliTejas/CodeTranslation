#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<ll> sum(N, 0);
	for (int i = 0; i < N - 1; i++) {
		sum[i + 1] = sum[i] + A[N - 1 - i];
		sum[i + 1] %= MOD;
	}
	ll ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ans += (A[i] * sum[N - 1 - i]) % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}