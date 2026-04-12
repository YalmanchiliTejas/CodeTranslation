#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fst first
#define snd second
const ll mod = 1000000007;
const ll INF = mod * mod;

ll modinv[1010];
ll fact[1010];

ll mpow(ll x, ll r) {
	if (r == 0)return 1LL;
	if (r == 1LL)return x;
	ll temp = mpow(x, r / 2LL);
	temp = temp * temp%mod;
	temp=temp*((r % 2LL) ? x : 1LL) % mod;
	return temp;
}
void get_modinv() {
	ll t = 1LL;
	fact[0] = 1;
	for (ll i = 1LL; i <= 1000LL; i++) {
		t = t*i%mod;
		fact[i] = t;
	}
	modinv[1000] = mpow(t, mod - 2);
	for (ll i = 1LL; i <= 1000LL; i++) {
		modinv[1000 - i] = modinv[1000 - i + 1] * (1000 - i + 1) % mod;
	}
}

int main() {
	int n, sizel, sizer, numl, numr;
	cin >> n >> sizel >> sizer >> numl >> numr;

	/* get mod inverse */
	get_modinv();

	ll dp[1010] = {};
	ll invp[1010][1010] = {};
	dp[0] = 1;
	for (ll i = sizel; i <= sizer; i++) {
		invp[i][numl] = mpow(modinv[i], numl);
		for (int r = numl + 1; r <= numr; r++) {
			invp[i][r] = invp[i][r - 1] * modinv[i] % mod;
		}
		for (ll j = n; j >= 0; j--) {
			for (ll k = numl; k <= numr; k++) {
				if (i*k > j)break;
				if (dp[j - k * i] == 0)continue;
				dp[j] += dp[j - k * i] *fact[n-j+k*i]%mod*modinv[n-j]%mod*modinv[k]%mod*invp[i][k]%mod;
				dp[j] %= mod;
			}
		}
	}
	cout << dp[n] << endl;

	return 0;
}
