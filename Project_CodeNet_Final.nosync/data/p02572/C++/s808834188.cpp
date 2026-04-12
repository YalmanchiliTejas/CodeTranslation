#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long int ll;
const ll MOD = 1e9 +7;
ll a[200010], acum[200010];

ll mod(ll a) {
	return ((a % MOD) + MOD) % MOD;
}

int main() {
	optimizar_io
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		acum[i] = a[i];
	}
	for (int i = 1; i < n; i++) acum[i] = mod(acum[i] + acum[i - 1]);
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll tmp = mod(acum[n - 1] - acum[i - 1]);
		tmp = mod(tmp * a[i - 1]);
		ans = mod(ans + tmp);
	}
	cout << ans << "\n";
	return 0;
}