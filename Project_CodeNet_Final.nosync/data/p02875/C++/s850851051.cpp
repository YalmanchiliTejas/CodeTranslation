#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const ll MOD = 998244353;
const int MX = TEN(7) + 10;
ll inv[MX], fact[MX], ifact[MX];
ll p2[MX];

void init() {
	inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	}
	fact[0] = ifact[0] = p2[0] = 1;
	for (int i = 1; i < MX; ++i) {
		p2[i] = p2[i-1] * 2 % MOD;
		fact[i] = fact[i-1] * i % MOD;
		ifact[i] = ifact[i-1] * inv[i] % MOD;
	}
}

ll comb(int n, int r) {
	if (n < 0 || r < 0 || r > n) return 0;
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main() {
	init();

	int N; cin >> N;
	ll all = 1;
	rep(i, N) all = all * 3 % MOD;
	ll ng = 0;

	for (int i = N / 2 + 1; i <= N; ++i) {
		ll a = comb(N, i) * p2[N-i] % MOD;
		ng += a;
		if (ng >= MOD) ng -= MOD;
	}

	ng = ng * 2 % MOD;
	all -= ng;
	if (all < 0) all += MOD;
	cout << all << endl;

	return 0;
}