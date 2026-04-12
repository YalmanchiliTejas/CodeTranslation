#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define nmax_def 110000
#define Cmax_def 2200
#define mod 998244353
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

vl pow_;
vector<vl> pow_23;
void pow_ini(ll n) {
	pow_.push_back(n);
	rep(j, 62) {
		ll nxt = pow_[j] * pow_[j];
		nxt %= mod;
		pow_.push_back(nxt);
	}
	for (ll i = 2; i <= 3; i++) {
		vl powtmp;
		powtmp.push_back(i);
		rep(j, 62) {
			ll nxt = powtmp[j] * powtmp[j];
			nxt %= mod;
			powtmp.push_back(nxt);
		}
		pow_23.push_back(powtmp);
	}
	return;
}

ll pow1(ll k) {
	ll ans = 1;
	rep(ntmp, 62) {
		if ((k >> ntmp) % 2 == 1) {
			ans *= pow_[ntmp];
			ans %= mod;
		}
	}
	return ans;
}

ll pow1_23(ll i, ll k) {
	ll ans = 1;
	rep(ntmp, 62) {
		if ((k >> ntmp) % 2 == 1) {
			ans *= pow_23[i - 2][ntmp];
			ans %= mod;
		}
	}
	return ans;
}

vl fact;
vl fact_inv;

void fact_ini(ll n) {
	fact.push_back(1);
	fact.push_back(1);
	for (ll i = 2; i <= n; i++) {
		ll fact_tmp = fact[i - 1] * i;
		fact_tmp %= mod;
		fact.push_back(fact_tmp);
	}
	fact_inv.resize(n + 1);
	pow_ini(fact[n]);
	fact_inv[n] = pow1(mod - 2);
	for (ll i = n - 1; i >= 0; i--) {
		fact_inv[i] = fact_inv[i + 1] * (i + 1);
		fact_inv[i] %= mod;
	}
}

ll nCm(ll n, ll m) {
	ll ans = fact[n] * fact_inv[m];
	ans %= mod;
	ans *= fact_inv[n - m];
	ans %= mod;
	return ans;
}

int main() {
	fact_ini(2 * pow(10, 7));
	ll N;
	cin >> N;
	ll ans1 = pow1_23(3, N);
	ll ans2 = 0;
	ll M = N / 2 + 1;
	for (ll i = M; i <= N; i++) {
		ll anstmp = nCm(N, i);
		anstmp *= pow1_23(2, N - i);
		anstmp %= mod;
		ans2 += anstmp;
	}
	ans2 *= 2;
	ans2 %= mod;
	ll ans = ans1 - ans2 + mod;
	ans %= mod;
	cout << ans << endl;
	return 0;
}