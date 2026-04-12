#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)




typedef long long ll;
#define MOD 1000000007
const int NUM_FAC = 2000001;
ll modfact(ll x) {
	static ll _fact[NUM_FAC + 1];
	if (_fact[0] == 0) {
		_fact[0] = 1;
		for (int i = 1; i <= NUM_FAC; ++i) _fact[i] = _fact[i - 1] * i%MOD;
	}
	return _fact[x];
}
ll modpow(ll a, ll n) {
	a %= MOD;
	if (a == 0) return 0;
	ll r = 1;
	while (n) r = r*((n % 2) ? a : 1) % MOD, a = a*a%MOD, n >>= 1;
	return r;
}
ll moddiv(ll a, ll b)
{
	ll ap_2 = modpow(b, MOD - 2);
	return (a * ap_2) % MOD;
}
ll aCb(ll a, ll b) {
	return moddiv(modfact(a), (modfact(a - b) * modfact(b)) % MOD);
}
ll aPb(ll a, ll b) {
	return moddiv(modfact(a), modfact(a - b));
}
//-----------------------------------------------------------------
ll dp[1010][1010];
int N, A, B, C, D;
ll f(ll gn, ll re) {
	if (re == 0) return 1;
	if (gn < A) return 0;

	if (0 <= dp[gn][re]) return dp[gn][re];

	ll ret = f(gn - 1, re);
	rep(i, 1, re / gn + 1) {
		if (i < C) continue;
		if (D < i) break;

		ll c = i;
		if (0 <= re - gn * c) {
			ll t = moddiv(aPb(re, gn * c), modpow(modfact(gn), c)) * f(gn - 1, re - gn * c);
			t %= MOD;
			t = moddiv(t, modfact(c));
			//printf("<%lld, %lld, %lld> = %lld\n",re, gn, c, t);
			ret = (ret + t) % MOD;
		}
	}

	return dp[gn][re] = ret;
}
//-----------------------------------------------------------------
int main() {
	cin >> N >> A >> B >> C >> D;
	rep(i, 0, 1010) rep(j, 0, 1010) dp[i][j] = -1;
	ll ans = f(B, N);
	cout << ans << endl;
}