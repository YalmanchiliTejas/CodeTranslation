#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MOD = (int)(1e+9) + 7;
const int INV = (MOD + 1) / 2;
int N;
ll sum, pow_A;
vector<int> A;

void input_init(void) {
	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	sum = (ll)0;
	for (int i = 0; i < N; ++i) {
		sum += A[i];
		sum %= MOD;
	}
}

ll solve(void) {
	pow_A = (ll)0;
	for (int i = 0; i < N; ++i) {
		ll p2 = (ll)A[i] * A[i];
		p2 %= MOD;
		pow_A += p2;
		pow_A %= MOD;
	}
	ll val = (sum * sum) % MOD;
	val = ((val + MOD) - pow_A) % MOD;
	val *= INV;
	val %= MOD;
	return val;
}

int main(void) {
	input_init();
	ll ans = solve();
	cout << ans << '\n';
	return 0;
}
