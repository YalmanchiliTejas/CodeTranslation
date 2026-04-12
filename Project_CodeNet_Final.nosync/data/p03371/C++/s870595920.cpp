#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
	ll A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	ll M = max(X,Y);
	ll ans = min(A * X + B * Y, 2 * M * C);
	rep(z,2*M+1) {
		ll x = max(0LL, X - z/2LL);
		ll y = max(0LL, Y - z/2LL);
		ans = min(ans, A*x+B*y+C*z);
	}
	cout << ans << endl;

	return 0;
}
