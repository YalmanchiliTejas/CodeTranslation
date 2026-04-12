#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T & ref, const T  value) {
	if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
	if (ref < value) ref = value;
}

const ll mod = 1000000007;

ll mpow(ll x, ll n) {
	ll ans = 1; x %= mod;
	while (n != 0) {
		if (n & 1) ans = ans * x % mod;
		x = x * x % mod;
		n = n >> 1;
	}
	return ans;
}

ll inv_mod(ll a) { return mpow(a, mod - 2); }

class Factorial {
private:
	vector<ll> fac;
	vector<ll> ifac;
public:

	Factorial(ll N) {
		fac.push_back(1);
		for (int i = 0; i < N; i++) fac.push_back(fac[i] * (i + 1) % mod);
		ifac.resize(N + 1);
		ifac[N] = inv_mod(fac[N]);
		for (int i = 0; i < N; i++) ifac[N - 1 - i] = (ifac[N - i] * (N - i)) % mod;
	}

	ll fact(ll a) { return fac[a]; }
	ll ifact(ll a) { return ifac[a]; }

	ll cmb(ll a, ll b) {
		if (a == 0 && b == 0) return 1;
		if (a < b || a < 0 || b < 0) return 0;
		ll tmp = ifact(a - b) * ifact(b) % mod;
		return tmp * fac[a] % mod;
	}
	ll per(ll a, ll b) {
		if (a == 0 && b == 0) return 1;
		if (a < b || a < 0 || b < 0) return 0;
		return fac[a] * ifac[a - b] % mod;
	}
};

void solve1() {
	ll w, h, k;
	cin >> w >> h >> k;
	//xとyで分解する
	const ll all = w * h;
	Factorial f(all);
	ll sum = 0;
	map<ll, ll> memo;
	for (int x1 = 0; x1 < w - 1; x1++) {
		for (int x2 = x1 + 1; x2 < w; x2++) {
			ll dx = x2 - x1;
			//x1, x2... h通りあり
			memo[dx]++;
			dx *= h * h;
			dx %= mod;
			dx *= f.cmb(all - 2, k - 2);
			dx %= mod;
			sum += dx;
			sum %= mod;
		}
	}
	cout << sum << endl;
	ll sum2 = 0;
	for (int y1 = 0; y1 < h - 1; y1++) {
		for (int y2 = y1 + 1; y2 < h; y2++) {
			ll dy = y2 - y1;
			//x1, x2... h通りあり
			dy *= w * w;
			dy %= mod;
			dy *= f.cmb(all - 2, k - 2);
			dy %= mod;
			sum2 += dy;
			sum2 %= mod;
		}
	}
	cout << (sum + sum2) % mod << endl;
}

int main() {
	//solve1();
	ll w, h, k;
	cin >> w >> h >> k;
	//xとyで分解する
	const ll all = w * h;
	Factorial f(all);
	ll wsum = 0;
	for (int i = 1; i < w; i++) {
		wsum += i * (w - i);
		wsum %= mod;
	}
	//cout << wsum << endl;
	wsum %= mod;
	wsum *= h * h;
	wsum %= mod;
	wsum *= f.cmb(all - 2, k - 2);
	wsum %= mod;
	ll hsum = 0;
	for (int i = 1; i < h; i++) {
		hsum += i * (h - i);
		hsum %= mod;
	}
	hsum %= mod;
	hsum *= w * w;
	hsum %= mod;
	hsum *= f.cmb(all - 2, k - 2);
	hsum %= mod;
	ll sum = hsum + wsum;
	sum %= mod;
	cout << sum << endl;
	return 0;
}
