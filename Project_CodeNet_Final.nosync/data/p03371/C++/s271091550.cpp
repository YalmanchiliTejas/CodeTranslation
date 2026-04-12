#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll INF = 100100100100;

int main() {
	ll A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	ll ans = INF;
	ll maxVal = max(X, Y);
	for (int ii = 0; ii <= maxVal; ++ii){
		ll anum = max(X-ii, 0LL);
		ll bnum = max(Y-ii, 0LL);
		ll abnum = ii * 2;
		ll val = anum*A + bnum*B + abnum*C;
		ans = min(ans, val);
	}

	cout << ans << "\n";

	return 0;
}
