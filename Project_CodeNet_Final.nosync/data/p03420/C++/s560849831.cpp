#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	ll N, K;
	cin >> N >> K;
	ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		ll p = N / i;
		ll r = N - p*i;
		ans += max(0LL, i - K) * p;
		ans += max(r - K + 1, 0LL);
	}
	if (K == 0)ans -= N;
	cout << ans << endl;
	return 0;
}