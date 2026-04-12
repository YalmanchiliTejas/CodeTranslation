#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<class T>
istream& operator >> (istream& is, vector<T>& v)
{
	for (auto &i : v) is >> i;
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	const string delimiter = "\n";
	REP(i, v.size())
	{
		os << v[i];
		if (i != v.size() - 1) os << delimiter;
	}
	return os;
}
/*--------------------template--------------------*/
template <int M, bool IsPrime = false> class Modulo {
	using ll = long long;
	int n;
	static typename enable_if<IsPrime, ll>::type inv(ll a, ll p) {
		return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
	}

public:
	Modulo() : n(0) { ; }
	Modulo(int m) : n(m) {
		if (n >= M)
			n %= M;
		else if (n < 0)
			n = (n % M + M) % M;
	}
	Modulo(ll m) {
		if (m >= M)
			m %= M;
		else if (m < 0)
			m = (m % M + M) % M;
		n = m;
	}
	explicit operator int() const { return n; }
	explicit operator ll() const { return n; }
	bool operator==(const Modulo &a) const { return n == a.n; }
	Modulo &operator+=(const Modulo &a) {
		n += a.n;
		if (n >= M) n -= M;
		return *this;
	}
	Modulo &operator-=(const Modulo &a) {
		n -= a.n;
		if (n < 0) n += M;
		return *this;
	}
	Modulo &operator*=(const Modulo &a) {
		n = (ll(n) * a.n) % M;
		return *this;
	}
	Modulo operator+(const Modulo &a) const {
		Modulo res = *this;
		return res += a;
	}
	Modulo operator-(const Modulo &a) const {
		Modulo res = *this;
		return res -= a;
	}
	Modulo operator*(const Modulo &a) const {
		Modulo res = *this;
		return res *= a;
	}
	Modulo operator^(int m) const {
		if (m == 0) return Modulo(1);
		const Modulo a = *this;
		Modulo res = (a * a) ^ (m / 2);
		return m % 2 ? res * a : res;
	}
	typename enable_if<IsPrime, Modulo>::type operator/(const Modulo &a) const {
		return *this * inv(ll(a), M);
	}
	typename enable_if<IsPrime, Modulo>::type operator/=(const Modulo &a) {
		return *this *= inv(ll(a), M);
	}
};

template <int M, bool IsPrime = false> bool is_zero(Modulo<M, IsPrime> x) {
	return int(x) == 0;
}
template <int M, bool IsPrime = false> int abs(Modulo<M, IsPrime> x) {
	return int(x);
}

const int mod = 1000000007;

template <int M = mod> Modulo<M, true> fact(int n, bool sw = true) {
	static vector<Modulo<M, true>> v1 = { 1 }, v2 = { 1 };
	if (n >= (int)v1.size()) {
		const int from = v1.size(), to = n + 1024;
		v1.reserve(to);
		v2.reserve(to);
		for (int i = from; i < to; ++i) {
			v1.push_back(v1.back() * Modulo<M, true>(i));
			v2.push_back(v2.back() / Modulo<M, true>(i));
		}
	}
	return sw ? v1[n] : v2[n];
}

template <int M = mod> Modulo<M, true> comb(int a, int b) {
	if (b < 0 || b > a) return 0;
	return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a - b, false);
}

using Mod = Modulo<mod, true>;

ll n, a, b, c, d;
ll dp[1111][1111];
ll memo_comb[1111][1111];
ll memo_fact[1111];

Mod comb_(ll a, ll b)
{
	if (memo_comb[a][b] >= 0) return memo_comb[a][b];
	return memo_comb[a][b] = int(comb<mod>(a, b));
}

Mod fact_(ll a)
{
	if (memo_fact[a] >= 0) return memo_fact[a];
	return memo_fact[a] = int(fact<mod>(a));

}

ll solve(int i, int rem)
{
	if (dp[i][rem] >= 0) return dp[i][rem];
	int num = a + i;
	if (num > b)
	{
		if (rem == 0) return 1;
		else return 0;
	}
	Mod res = 0;
	res += solve(i + 1, rem);
	FOR(j, c, d + 1)
	{
		int use = num * j;
		if (use > rem) break;
		Mod tmp = 1;
		REP(k, j)
		{
			tmp *= comb_(rem - k * num, num);
		}
		tmp /= fact_(j);
		res += tmp * solve(i + 1, rem - use);
	}
	return dp[i][rem] = int(res);
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	MS(dp, -1);
	MS(memo_comb, -1);
	MS(memo_fact, -1);
	cin >> n >> a >> b >> c >> d;
	cout << solve(0, n) << endl;
	return 0;
}