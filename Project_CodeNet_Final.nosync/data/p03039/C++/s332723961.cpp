#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

const ll MOD = 1e9 + 7;

ll modpow(ll x, ll k) {
	if (k == 0) return 1;
	ll ret = modpow(x, k/2);
	ret = (ret * ret) % MOD;
	if (k%2 == 1) ret = (ret * x) % MOD;
	return ret;
}

ll fact(ll n) {
	ll ret = 1;
	for (int i = 1; i <= n; i++)
		ret = (ret * i) % MOD;
	return ret;
}

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;

	ll a = 0, b = 0;
	for (int i = 1; i < m; i++)
		a = (a + n * i * (m-i)) % MOD;
	a = (a * n) % MOD;
	for (int i = 1; i < n; i++)
		b = (b + m * i * (n-i)) % MOD;
	b = (b * m) % MOD;

	ll c = fact(n*m-2);
	c *= modpow(fact(k-2), MOD-2); c %= MOD;
	c *= modpow(fact(n*m-k), MOD-2); c %= MOD;
	//cerr << a << ' ' << b << ' ' << c << endl;

	ll ans = ((a+b) * c) % MOD;
	cout << ans << endl;
}
