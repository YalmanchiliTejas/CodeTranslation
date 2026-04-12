#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	ll sum = 0, sum2 = 0;
	for (int i = 0; i < n; ++i) {
		ll a; cin >> a;
		sum = (sum + a) % MOD;
		sum2 = (sum2 + a * a) % MOD;
	}

	ll ans = (sum * sum) % MOD;
	ans -= sum2;
	while (ans < 0) ans += MOD;
	ans %= MOD;
	if (ans % 2) ans += MOD;
	ans = (ans / 2) % MOD;

	cout << ans << endl;

	return 0;
}
