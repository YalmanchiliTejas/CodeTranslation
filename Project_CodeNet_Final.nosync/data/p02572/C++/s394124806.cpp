#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll const m = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<ll> A(N), SumAj(N - 1);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	SumAj[N - 2] = A[N - 1];
	for (int i = N - 3; i >= 0; i--) {
		SumAj[i] = SumAj[i + 1] + A[i + 1];
		SumAj[i] %= m;
	}
	ll ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ans = (ans + A[i] * SumAj[i]) % m;
	}
	cout << ans << "\n";
	return 0;
}
