#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> A(n);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		s += A[i];
		s %= MOD;
	}
	ll ans = (s * s) % MOD;
	for (int i = 0; i < n; i++) {
		ans -= A[i] * A[i];
		ans %= MOD;
		if (ans < 0) ans += MOD;
	}
	if (ans % 2 == 0) {
		cout << ans / 2 << endl;
	} else {
		ans *= 500000004LL;
		ans %= MOD;
		cout << ans << endl;
	}
}

//(a + b + c)**2  - a**2 - b**2 - c**2 / 2
