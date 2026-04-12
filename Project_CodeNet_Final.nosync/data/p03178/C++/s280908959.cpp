#include "bits/stdc++.h"

using ll = long long;

using namespace std;
#define int ll

// 0 -> a-1
#define rep(i, a) for (int i = 0; (i) < (int)(a); (i)++)
// a -> b-1
#define reps(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
// a-1 -> 0
#define rrep(i, a) for (int i = (int)a - 1; (i) >= 0; (i)--)
// a-1 -> b
#define rreps(i, a, b) for (int i = (int)(a)-1; (i) >= (int)(b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
// next_permutation(all(v))
#define PERM(v) next_permutation(all(v))
/*sort(all(v));
(v).erase(unique(all(v)), v.end())*/
#define UNIQUE(v)                                                              \
	sort(all(v));                                                              \
	(v).erase(unique(all(v)), v.end())
#define CIN(type, x)                                                           \
	type x;                                                                    \
	cin >> x
#define YES(f)                                                                 \
	if ((f)) {                                                                 \
		cout << "YES" << endl;                                                 \
	} else {                                                                   \
		cout << "NO" << endl;                                                  \
	}
#define Yes(f)                                                                 \
	if ((f)) {                                                                 \
		cout << "Yes" << endl;                                                 \
	} else {                                                                   \
		cout << "No" << endl;                                                  \
	}
#define MINV(v) min_element(all(v))
#define MAXV(v) max_element(all(v))
#define MIN3(a, b, c) min(min(a, b), c)
#define MIN4(a, b, c, d) min(MIN3(a, b, c), d)
#define MIN5(a, b, c, d, e) min(MIN4(a, b, c, d), e)
#define MIN6(a, b, c, d, e, f) min(MIN5(a, b, c, d, e), f)
#define MAX3(a, b, c) max(max(a, b), c)
#define MAX4(a, b, c, d) max(MAX3(a, b, c), d)
#define MAX5(a, b, c, d, e) max(MAX4(a, b, c, d), e)
#define MAX6(a, b, c, d, e, f) max(MAX5(a, b, c, d, e), f)
// b is [a, c)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
// c is [a, e) && d is [b, f)
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmin3(a, b, c) a = MIN3(a, (b), (c))
#define chmin4(a, b, c, d) a = MIN4(a, (b), (c), (d))
#define chmin5(a, b, c, d, e) a = MIN5(a, (b), (c), (d), (e))
#define chmin6(a, b, c, d, e, f) a = MIN6(a, (b), (c), (d), (e), (f))
#define chmax(a, b) a = max(a, (b))
#define chmax3(a, b, c) a = MAX3(a, (b), (c))
#define chmax4(a, b, c, d) a = MAX4(a, (b), (c), (d))
#define chmax5(a, b, c, d, e) a = MAX5(a, (b), (c), (d), (e))
#define chmax6(a, b, c, d, e, f) a = MAX6(a, (b), (c), (d), (e), (f))
#define fcout cout << fixed << setprecision(12)
#define RS resize
#define CINV(v, N)                                                             \
	do {                                                                       \
		v.RS(N);                                                               \
		rep (i, N)                                                             \
			cin >> v[i];                                                       \
	} while (0);

#define RCINV(v, N)                                                            \
	do {                                                                       \
		v.RS(N);                                                               \
		rrep (i, N)                                                            \
			cin >> v[i];                                                       \
	} while (0);
#define MOD 1000000007

template <class T> inline T GET()
{
	T x;
	cin >> x;
	return x;
}

void init();
void solve();

signed main()
{
	init();
	solve();
}

template <class T, char d = '\n'> struct Vector
{
	vector<T> v;
	Vector(int sz) : v(sz) {}
	Vector(int sz, T t) : v(sz, t) {}
	Vector() : v(0) {}
	Vector(vector<T> t) : v(t) {}
	inline auto begin() { return v.begin(); }
	inline auto end() { return v.end(); }
	inline auto rbegin() { return v.rbegin(); }
	inline auto rend() { return v.rend(); }
	inline int size() { return v.size(); }
	inline auto resize(int sz) { v.resize(sz); }
	inline auto resize(int sz, T t) { v.resize(sz, t); }
	inline auto empty() { v.empty(); }
	inline auto reserve(int sz) { v.reserve(sz); }
	inline auto push_back(T t) { v.push_back(t); }
	inline auto pop_back() { v.pop_back(); }
	inline auto assign(int sz, const T &t) { v.assign(sz, t); }
	inline auto &front() { return v.front(); }
	inline auto &back() { return v.back(); }
	inline auto insert(const typename vector<T>::iterator p, const T &t)
	{
		v.insert(p, t);
	}
	inline auto insert(const typename vector<T>::iterator p,
					   typename vector<T>::iterator f,
					   typename vector<T>::iterator l)
	{
		v.insert(p, f, l);
	}

	inline auto erase(const typename vector<T>::iterator p) { v.erase(p); }
	inline auto erase(const typename vector<T>::iterator f,
					  const typename vector<T>::iterator s)
	{
		v.erase(f, s);
	}
	inline auto emplace_back(T &t) { v.emplace_back(t); }
	inline auto swap(Vector<T> &f) { v.swap(f.v); }
	inline auto clear() { v.clear(); }
	inline auto &operator[](size_t pos) { return v[pos]; }
	inline auto operator<(const Vector &a) { return v < a.v; }
	inline auto operator>(const Vector &a) { return a < (*this); }
	inline auto operator>=(const Vector &a) { return !((*this) < a); }
	inline auto operator<=(const Vector &a) { return !(a < (*this)); }
	inline auto operator==(const Vector &a)
	{
		return !(a < (*this)) && !((*this) < a);
	}

	inline friend istream &operator>>(istream &lhs, Vector &rhs)
	{
		for (auto &x : rhs) lhs >> x;
		return lhs;
	}
	inline friend ostream &operator<<(ostream &lhs, Vector &rhs)
	{
		for (int i = 0; i + 1 < rhs.size(); i++) lhs << rhs[i] << d;
		if (rhs.size()) lhs << rhs.back();
		return lhs;
	}
	inline auto make_accumulate_sum(T init)
	{
		Vector<T> res;
		res.push_back(init);
		for (auto x : v) {
			auto y = res.back();
			res.push_back(y + x);
		}
		return res;
	}
};

template<int mod> struct ModInt {
	using ll = long long;
	int x;
	template<class T>
	ModInt(T a) {
		x = a % mod;
		if (x < 0) {
			x += mod;
		}
	}
	ModInt() : x(0) {}
	inline ModInt& operator+=(const ModInt& rhs)
	{
		(*this) += rhs.x;
		return *this;
	}
	template<class T>
	inline ModInt& operator+=(const T rhs)
	{
		x += rhs % mod;
		if (x < 0) x += mod;
		x %= mod;
		return *this;
	}
	inline ModInt& operator-=(const ModInt& rhs)
	{
		(*this) -= rhs.x;
		return *this;
	}
	template<class T>
	inline ModInt& operator-=(const T rhs)
	{
		x -= rhs % mod;
		if (x < 0) x += mod;
		x %= mod;
		return *this;
	}
	inline ModInt& operator*=(const ModInt& rhs)
	{
		(*this) *= rhs.x;
		return *this;
	}
	template<class T>
	inline ModInt& operator*=(const T rhs)
	{
		ll res = (ll) x * (rhs % mod);
		x = res % mod;
		if (x < 0) x += mod;
		return *this;
	}
	inline ModInt& operator/=(const ModInt& rhs)
	{
		(*this) /= rhs.x;
		return *this;
	}
	template<class T>
	inline ModInt& operator/=(const T rhs)
	{
		int t = rhs % mod;
		if (t < 0) t += mod;
		ll res = modpow(t);
		(*this) *= res;
		return *this;
	}
	inline ModInt& operator=(const ModInt& rhs)
	{
		(*this) = rhs.x;
		return *this;
	}
	template<class T>
	inline ModInt& operator=(const T rhs)
	{
		x = rhs % mod;
		if (x < 0) x += mod;
		return *this;
	}
	inline int operator==(const ModInt& rhs) const
	{
		return (*this) == rhs.x;
	}
	template<class T>
	inline int operator==(const T rhs) const
	{
		ModInt t(rhs);
		return (*this).x == t.x;
	}
	inline int operator!=(const ModInt& rhs) const
	{
		return (*this) != rhs.x;
	}
	inline int operator!=(const int rhs) const
	{
		ModInt t(rhs);
		return (*this).x != t.x;
	}
	inline ModInt operator++(signed unused)
	{
		ModInt res((*this).x);
		++(*this);
		return res;
	}
	inline ModInt& operator++()
	{
		(*this) += 1;
		return (*this);
	}
	inline ModInt operator--(signed unused)
	{
		ModInt res((*this).x);
		--(*this);
		return res;
	}
	inline ModInt& operator--()
	{
		(*this) -= 1;
		return (*this);
	}
	inline ModInt operator+() const
	{
		return (*this);
	}
	inline ModInt operator-() const
	{
		return (*this).x ? ModInt(mod - (*this).x) : ModInt(0);
	}
	template<class T>
	int modpow(const T val, int p = mod - 2)
	{
		if (p == 0) return 1;
		if (p % 2) return (long long) val * modpow(val, p-1) % mod;
		long long t = modpow(val, p/2);
		int res = t * t % mod;
		return res;
	}
	operator int() const
	{
		return x;
	}
	friend ostream& operator<<(ostream& lhs, const ModInt& rhs)
	{
		lhs << rhs.x;
		return lhs;
	}
	friend istream& operator>>(istream& lhs, ModInt& rhs)
	{
		long long t;
		lhs >> t;
		rhs.x = t % mod;
		if (rhs.x < 0) rhs += mod;
		return lhs;
	}
	friend const ModInt operator+(const ModInt& lhs, const ModInt& rhs)  {return ModInt(lhs) += rhs;}
	template<class T>
	friend const ModInt operator+(const ModInt& lhs, const T rhs)        {return ModInt(lhs) += rhs;}
	template<class T>
	friend const ModInt operator+(T lhs, const ModInt& rhs)              {return ModInt(lhs) += rhs;}
	friend const ModInt operator-(const ModInt& lhs, const ModInt& rhs)  {return ModInt(lhs) -= rhs;}
	template<class T>
	friend const ModInt operator-(const ModInt& lhs, const T rhs)        {return ModInt(lhs) -= rhs;}
	template<class T>
	friend const ModInt operator-(T lhs, const ModInt& rhs)              {return ModInt(lhs) -= rhs;}
	friend const ModInt operator*(const ModInt& lhs, const ModInt& rhs)  {return ModInt(lhs) *= rhs;}
	template<class T>
	friend const ModInt operator*(const ModInt& lhs, const T rhs)        {return ModInt(lhs) *= rhs;}
	template<class T>
	friend const ModInt operator*(T lhs, const ModInt& rhs)              {return ModInt(lhs) *= rhs;}
	friend const ModInt operator/(const ModInt& lhs, const ModInt& rhs)  {return ModInt(lhs) /= rhs;}
	template<class T>
	friend const ModInt operator/(const ModInt& lhs, const T rhs)        {return ModInt(lhs) /= rhs;}
	template<class T>
	friend const ModInt operator/(T lhs, const ModInt& rhs)              {return ModInt(lhs) /= rhs;}
	template<class T>
	friend const int    operator==(T lhs, const ModInt& rhs)             {return ModInt(lhs) == rhs;}
	template<class T>
	friend const int    operator!=(T lhs, const ModInt& rhs)             {return ModInt(lhs) != rhs;}
};
using modint = ModInt<1000000007>;


//        pos mod D bind
modint dp[20000][100][2];
bool ch[20000][100][2];
int L;
string K;
int D;

modint dfs(int pos, int m, int b)
{
	modint &res = dp[pos][m][b];
	if (ch[pos][m][b]) return res;
	ch[pos][m][b] = true;
	res = 0;
	int to = b == 0 ? 10 : (K[pos] - '0') + 1;
	if (pos == L - 1) {
//		cout << "A " << pos << " " << m << " " << b << " ";
		rep(i, to) {
			if (i % D == m) res++;
		}
//		cout << res << endl;
		return res;
	}
	rep(i, to) {
		res += dfs(pos + 1, ((m - i) % D + D) % D, b && i == to - 1);
	}
//	cout << "B " << pos << " " << m << " " << b << " " << res << endl;
	return res;
}

void init()
{
	cin >> K >> D;
	L = K.size();
	modint res = dfs(0, 0, 1) - 1;
	cout << res << endl;
}

void solve()
{
}
