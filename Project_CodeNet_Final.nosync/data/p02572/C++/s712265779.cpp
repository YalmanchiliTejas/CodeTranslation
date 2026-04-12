#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define INF 0x7fffffff
#define LL_INF 0x7fffffffffffffff
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

ll mod = 1e9+7;
ll power(ll a, ll n) {
	ll res = 1;
	while(n > 0) {
		if(n & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return res;
}


int main(void) {
	int n; cin >> n;
	ll s = 0, ss = 0;
	for(int i=0;i<n;i++) {
		ll a;
		cin >> a;
		s += a; s %= mod;
		ss += (a*a) % mod; ss %= mod;
	}
	ll ans = ((s * s) % mod - ss) % mod;
	if(ans < 0) ans += mod;
	ans *= power(2, mod - 2);
	ans %= mod;
	if(ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}

