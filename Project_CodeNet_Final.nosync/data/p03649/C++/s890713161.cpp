#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
vector<ll> A;
ll ans, max_a;

void calcu(void) {
	ll k = 0;
	for (int i = 0; i < N; ++i)
		k += A[i] / N;
	ans += k;
	max_a = -1LL;
	for (int i = 0; i < N; ++i) {
		A[i] = (A[i] % N) + (k - A[i] / N);
		max_a = max(max_a, A[i]);
	}
}

int main(void) {
	cin >> N;

	A.resize(N);
	max_a = -1LL;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		max_a = max(max_a, A[i]);
	}

	ans = 0LL;
	while (max_a > N - 1)
		calcu();

	cout << ans << '\n';
	return 0;
}
