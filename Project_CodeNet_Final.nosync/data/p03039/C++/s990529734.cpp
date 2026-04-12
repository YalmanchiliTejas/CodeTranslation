#include<bits/stdc++.h>

using namespace std;
#define rep(i,m,n) for(int i=m;i<n;++i)
#define llrep(i,m,n) for(ll i=m;i<n;++i)
#define inf 1000000000
#define llinf 1000000000000000000
#define mod 1000000007
#define ll long long
#define mp make_pair
#define all(v) v.begin(),v.end()

ll fac(ll n) {
	ll hoge = 1;
	rep(i, 1, n + 1) {
		hoge = (hoge * i) % mod;
	}
	return hoge;
}

ll inv(ll n) {
	int p = mod - 2;
	ll hoge = 1;
	ll tmp = n;
	while (p) {
		if ((p & 1) == 1) {
			hoge = (hoge * tmp) % mod;
		}
		tmp = (tmp * tmp) % mod;
		p >>= 1;
	}
	return hoge;
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = (((((n - 1) * n * (n + 1) / 6) % mod) * ((m * m) % mod)) % mod + ((((m - 1) * m * (m + 1) / 6) % mod) * ((n * n) % mod)) % mod) % mod;
	ans *= (((fac(n * m - 2) * inv(fac(k - 2))) % mod) * inv(fac(n * m - k))) % mod;
	ans %= mod;
	cout << ans << endl;
}