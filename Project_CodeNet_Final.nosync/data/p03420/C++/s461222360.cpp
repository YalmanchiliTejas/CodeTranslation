#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n, k; cin >> n >> k;
	ll ans = 0;

	rep(b, k + 1, n + 1) {
		ll p = n / b, q = n % b;
		ll lv = 0;
		lv += p * (b - k);
		if (q >= k) lv += q - k + 1;
		//cerr << b << " " << lv << endl;
		ans += lv;
	}
	if (k == 0) ans -= n;

	cout << ans << endl;
}
