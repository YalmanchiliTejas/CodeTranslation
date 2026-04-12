#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N;
ll X;
vector<ll> L, P;

void calcu_level_len(void) {
	L.resize(N + 1);
	P.resize(N + 1);
	L[0] = P[0] = 1;
	for (int i = 1; i <= N; ++i) {
		L[i] = 2 * L[i - 1] + 3;
		P[i] = 2 * P[i - 1] + 1;
	}
}

ll rec(int n, ll x) {
	if (n == 0)
		return P[0];
	if (x == (ll)1)
		return (ll)0;
	else if (x > 1 && x <= 1 + L[n - 1])
		return rec(n - 1, x - 1);
	else if (x == 2 + L[n - 1])
		return P[n - 1] + 1;
	else if (x > 2 + L[n - 1] && x <= 2 + 2 * L[n - 1])
		return P[n - 1] + 1 + rec(n - 1, x - L[n - 1] - 2);
	else if (x == 3 + 2 * L[n - 1])
		return 2 * P[n - 1] + 1;

	return 0;
}

int main(void) {
	cin >> N >> X;

	calcu_level_len();
	ll ans = rec(N, X);

	cout << ans << '\n';
	return 0;
}
