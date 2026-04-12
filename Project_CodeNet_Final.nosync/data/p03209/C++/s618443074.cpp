
// D - Christmas

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll Y[51]; // レベルLバーガーの層の数

ll count_patties(ll L, ll X) {
	if (L == 0) {
		//if (X == 1) return 1;
		if (X >= 1) return 1;
		else return 0;
	}

	ll M = Y[L] / 2 + 1;

	if (X == 1) {
		return 0;
	} else if (X < M) {
		return count_patties(L-1, X-1);
	} else if (X == M) {
		return count_patties(L-1, X-1) + 1;
	} else if (X < Y[L]) {
		return count_patties(L-1, Y[L-1]) + 1 + count_patties(L-1, X-M);
	} else {  // X == Y[L]
		return count_patties(L-1, Y[L-1]) * 2 + 1;
	}
}

int main() {
	ll N, X;
	cin >> N >> X;

	Y[0] = 1;
	for (int i=0; i<50; i++) {
		Y[i+1] = Y[i] * 2 + 3;
	}

	ll ans = count_patties(N, X);

	cout << ans << endl;

	return 0;
}