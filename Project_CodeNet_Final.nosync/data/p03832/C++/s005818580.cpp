#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define pb push_back
using ll = long long;
using ld = long double;
constexpr ll mod = 1000000007LL;

ll comb[1010][1010];
ll factinv[1010];

void comb_init() {
	for(ll i = 1; i < 1010; i++) {
	for(ll j = 0; j < 1010; j++) {
		if(j > i) {
			comb[i][j] = 0;
			continue;
		}
		if(j == 0 || j == i) {
			comb[i][j] = 1;
			continue;
		}
		comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
	}}
	return;
}

ll mod_pow(ll a, ll n) {
	if(n == 0) return 1;
	if(n % 2) {
		return (a * mod_pow((a * a) % mod, n / 2)) % mod;
	} else {
		return mod_pow((a * a) % mod, n / 2) % mod;
	}
}

void factinv_init() {
	ll buf = 1;
	for(ll i = 1; i < 1010; i++) {
		buf *= i;
		buf %= mod;
		factinv[i] = mod_pow(buf, mod - 2);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	comb_init();
	factinv_init();
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	vector<ll> cnt(n + 1, 0);
	cnt[0] = 1;
	for(ll i = a; i <= b; i++) {
		vector<ll> ncnt(n + 1, 0);
		for(ll j = 0; j <= n; j++) {
			ncnt[j] += cnt[j];
			ncnt[j] %= mod;
			ll buf = 1;
			for(ll k = 1; k <= d; k++) {
				if(i * k > n - j) break;
				buf *= comb[n - (j + (k - 1) * i)][i];
				buf %= mod;
				if(k < c) continue;
				ncnt[j + i * k] += (((buf * cnt[j]) % mod) * factinv[k]) % mod;
				ncnt[j + i * k] %= mod;
			}
		}
		cnt = ncnt;
	}
	cout << cnt[n] << endl;
	return 0;
}