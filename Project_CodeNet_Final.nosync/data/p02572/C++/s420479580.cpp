#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

const ll MOD = 1e9 + 7;

ll powmod(ll a, ll b){
	if(b == 0) return 1;
	if(b & 1) {
		return a * powmod(a, b - 1) % MOD;
	} else {
		ll d = powmod(a, b / 2) % MOD;
		return d * d % MOD;
	}
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll s = 0;
	rep(i, n) {
		s += a[i];
		s %= MOD;
	}

	ll ss = 0;
	rep(i, n) {
		ss += a[i] * a[i] % MOD;
		ss %= MOD;
	}

	ll ans = s * s % MOD + (MOD - ss) % MOD;
	ans %= MOD;
	ans *= powmod(2ll, MOD - 2);
	ans %= MOD;

	cout << ans << endl;
}
