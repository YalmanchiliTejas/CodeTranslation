
// C - Half and Half

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	ll ans = INF;
	for (int c=0; c <= max(X * 2, Y * 2); c++) {
		int a = max(0LL, X - (c / 2));
		int b = max(0LL, Y - (c / 2));

		ll cost = A * a + B * b + C * c;
		ans = min(ans, cost);
	}

	cout << ans << endl;

	return 0;
}