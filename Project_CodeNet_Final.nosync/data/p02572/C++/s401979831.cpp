#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll N;
	cin >> N;
	ll A[N];
	for(int i = 0; i < N; i++) cin >> A[i];

	ll sum[N];
	sum[0] = A[0];
	for(int i = 1; i < N; i++) {
		sum[i] = sum[i - 1] + A[i];
		sum[i] %= mod;
	}

	ll ans = 0;
	for(int i = 0; i < N - 1; i++) {
		ans += (sum[N - 1] * A[i]) % mod - (sum[i] * A[i]) % mod;
		ans %= mod;
		if(ans < 0) ans += mod;
	}
	cout << ans;
	return 0;
}
