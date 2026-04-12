
//#pragma GCC optimize ("-O3")
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdio>
#include <string>
#include <bitset>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <queue>
#include <regex>
#include <cassert>
#include <map>
#include <type_traits>
#include <array>
#include <cassert>
#include <typeinfo>
#include <time.h>
#include <iomanip>
#include <random>
#include <sstream>
#include <complex>
#ifdef _MSC_VER
#include <intrin.h>
#define popcnt __popcnt64
//#  define __builtin_popcount __popcnt
#else
#define popcnt __builtin_popcountll
#endif
//#include "boost/variant.hpp"



using namespace std;

typedef long long ll;
constexpr ll MOD = 1000000007ll;
constexpr ll INF = 1LL << 60;

#define rep(i, N, M) for(ll i=N, i##_len=(M); i<i##_len; ++i)
#define rep_skip(i, N, M, ...) for(ll i=N, i##_len=(M); i<i##_len; i+=(skip))
#define rrep(i, N, M)  for(ll i=(M)-1, i##_len=(N-1); i>i##_len; --i)
#define repbit(bit, N, DIG) rep(bit, (N), (1LL<< (DIG)))
#define pb push_back
#define fir first
#define sec second
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define perm(c) sort(all(c));for(bool c##perm=1;c##perm;c##perm=next_permutation(all(c))) //perm(c){write(c)} writes all permutation of c 
constexpr ll dceil(ll x, ll y) { if (y < 0) { x *= -1; y *= -1; }; return x > 0 ? (x + y - 1) / y : x / y; } // ceil for x/y
constexpr ll dfloor(ll x, ll y) { if (y < 0) { x *= -1; y *= -1; };  return x > 0 ? x / y : -dceil((-x), y); } // floor for x/y

typedef pair<double, double> pd;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
template<typename T> using pq_greater = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using vpt = vector<complex<T>>;

template<int n>
struct tll_impl {
	using type = decltype(tuple_cat(tuple<ll>(), declval<typename tll_impl<n - 1>::type>()));
};
template<>
struct tll_impl<1> {
	using type = tuple<ll>;
};
template<int n>
using tll = typename tll_impl<n>::type;

template<class T>
constexpr ll SZ(T& v) { return static_cast<ll>(v.size()); };

template<int n, typename T>
struct vec_t_impl {
	using type = vector<typename vec_t_impl<n-1,T>::type>;
};
template<typename T>
struct vec_t_impl<1,T> {
	using type = vector<T>;
};
template<int n, typename T>
using vec_t = typename vec_t_impl<n, T>::type;
// check 
static_assert(is_same<vec_t<3,ll>, vector<vector<vector<ll>>>>::value, "");

// decompose vector into basetype and dimension.
template<typename T> 
struct vec_dec {
	static constexpr int dim = 0;
	using type  = T;
};
template<typename T>
struct vec_dec<vector<T>> {
	static constexpr int dim = vec_dec<T>::dim+1;
	using type  = typename vec_dec<T>::type;
};
static_assert(is_same<typename vec_dec<vec_t<3, ll>>::type, ll>::value, "");
static_assert(vec_dec<vec_t<3, ll>>::dim == 3, "");

template<typename T = ll>
vector<T> makev(size_t a) { return vector<T>(a); }

template<typename T = ll, typename... Ts>
auto makev(size_t a, Ts... ts) {
	return vector<decltype(makev<T>(ts...))>(a, makev<T>(ts...));
} // ex:  auto dp =  makev<ll>(4,5) => vector<vector<ll>> dp(4,vector<ll>(5));

template < typename T >
struct is_vector : std::false_type {}; // check if T is vector

template < typename T >
struct is_vector<vector<T>> : std::true_type {};
static_assert(is_vector<vector<ll>>::value == true && is_vector<ll>::value == false, "");

// check if T is vector
template < typename T>
struct is_pair : std::false_type {};

template < typename T, typename S >
struct is_pair<pair<T, S>> : std::true_type {};
static_assert(is_pair<pll>::value == true && is_pair<ll>::value == false, "");

template<typename T, typename V, typename enable_if<!is_vector<T>::value, nullptr_t>::type = nullptr>
void fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V, typename enable_if<is_vector<T>::value, nullptr_t>::type = nullptr>
void fill_v(T& t, const V& v) {
	for (auto &&x : t)
		fill_v(x, v);
} // ex:  fill_v(dp, INF);

namespace std {
	template<class T> bool operator<(const complex<T>& a, const complex<T>& b) {
		return a.real() == b.real() ? a.imag() < b.imag() : a.real() < b.real();
	}
};

template<typename T, typename S> istream& operator>>(istream& istr, pair<T, S>& x) { return istr>> x.first >> x.second; }
template<typename T> istream& operator>>(istream& istr, vector<T>& x) {	rep(i, 0, x.size()) istr >> x[i]; return istr; }
template<typename T> istream& operator>>(istream& istr, complex<T>& x) { T r, i; istr >> r >> i; x.real(r); x.imag(i); return istr; }

template<typename T, typename Delim_t = string, typename enable_if<!is_vector<T>::value, nullptr_t>::type = nullptr>
void write(T& x, Delim_t delim = " ") { cout << x << delim; }
template<typename T, typename Delim_t = string, typename enable_if<is_vector<T>::value, nullptr_t>::type = nullptr>
void write(T& x, Delim_t delim = " ") { rep(i, 0, x.size()) write(x[i], (i == (x.size() - 1) ? "" : delim)); cout << '\n'; }

template<typename T> void chmin(T &a, T b) {
	if (a > b) a = b;
}
template<typename T> void chmax(T &a, T b) {
	if (a < b) a = b;
}

vll seq(ll i, ll j) {
	vll res(j - i);
	rep(k, i, j) res[k] = i + k;
	return res;
}

constexpr ll POW_0(ll x, ll y) {
	if (y == 0)return 1;
	if (y == 1)return x ;
	if (y == 2)return x * x ;
	if (y % 2 == 0)return POW_0(POW_0(x, y / 2), 2LL);
	return ((POW_0(POW_0(x, y / 2), 2LL)) * (x)) ;
}

constexpr ll POW(ll x, ll y, ll mod = 0) {
	if (mod == 0)return POW_0(x, y);
	if (y == 0)return 1;
	if (y == 1)return x % mod;
	if (y == 2)return x * x % mod;
	if (y % 2 == 0)return POW(POW(x, y / 2, mod), 2LL, mod) % mod;
	return ((POW(POW(x, y / 2, mod), 2LL, mod)) * (x % mod)) % mod;
}

template<
	typename Inputs,
	typename Functor,
	typename T = typename Inputs::value_type>
	void sort_by(Inputs& inputs, Functor f) {
	std::sort(std::begin(inputs), std::end(inputs),
		[&f](const T& lhs, const T& rhs) { return f(lhs) < f(rhs); });
}

template<
	int pos,
	typename Inputs,
	typename T = typename Inputs::value_type>
	void sort_by(Inputs& inputs) {
	std::sort(std::begin(inputs), std::end(inputs),
		[](const T& lhs, const T& rhs) { return get<pos>(lhs) < get<pos>(rhs); });
}

template<
	typename Inputs,
	typename Functor,
	typename T = typename Inputs::value_type>
	void stable_sort_by(Inputs& inputs, Functor f) {
	std::stable_sort(std::begin(inputs), std::end(inputs),
		[&f](const T& lhs, const T& rhs) { return f(lhs) < f(rhs); });
}

template<typename Inputs>
void sort_uniq(Inputs& inputs) {
	sort(all(inputs));
	inputs.erase(unique(all(inputs)), inputs.end());
}

vector<string> split(const string& s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	if (s.size() > 0 && s.front() == delim) {
		elems.push_back("");
	}
	while (getline(ss, item, delim)) {
		if (!item.empty()) {
			elems.push_back(item);
		}
	}
	if (s.size() > 0 && s.back() == delim) {
		elems.push_back("");
	}
	return elems;
}

template<class T>
map<T,ll> inv_map(vector<T>& x) {
	map<T, ll> res;
	rep(i, 0, x.size()) {
		res[x[i]] = i;
	}
	return res;
}
template<class K, class V>
map<V, K> inv_map(map<K, V>& m) {
	map<V, K> res;
	for(const auto& x: m) {
		res[x.second] = x.first;
	}
	return res;
}
template<class T, class val_t = typename T::value_type, enable_if_t<!is_same<T, set<val_t>>::value >* = nullptr >
constexpr bool exist(const T& container, val_t val) { return find(all(container), val) != container.end(); }
template<class T, class val_t = typename T::value_type,  enable_if_t<is_same<T, set<val_t>>::value >* = nullptr >
constexpr bool exist(const T& container, val_t val) { return container.find(val) != container.end(); }

// inner prod: |a||b|cos(theta)
template<class T> T dot(complex<T> a, complex<T> b) {	return a.real() * b.real() + a.imag() * b.imag(); }
// outer prod |a||b|sin(theta)
template<class T> T cross(complex<T> a, complex<T> b) { return a.real() * b.imag() - a.imag() * b.real(); }




ll div_ferm(ll val, ll  b, ll mod) {
	return (val* POW(b, mod - 2, mod)) % mod;
}


// === Modint ===
//static uint_fast64_t runtime_modulus = MOD;

template <ll modulus = MOD> 
class modint 
{
public:
	ll val; 
	constexpr modint() : val(0) {}
	constexpr modint(ll x) : val((x %= mod()) < 0 ? x + mod() : x) {}
	constexpr modint(ll x, ll modulus_) {
		set_modulo(modulus_); val = (x %= mod()) < 0 ? x + mod() : x;
	}
	template<class Ret = ll &> 
	static auto modulo() -> std::enable_if_t<(modulus <= 0), Ret> { 
		static ll runtime_modulus= numeric_limits<ll>::max(); return runtime_modulus; // singleton technique
	}
	template<class Ret = const ll>
	static auto mod() -> std::enable_if_t<(modulus <= 0), Ret> { return modulo(); }

	template<class Ret = const ll>
	static constexpr auto mod()->std::enable_if_t<(modulus > 0), Ret> { return modulus; }

	template<ll modulus_ = modulus, enable_if_t<(modulus_ <= 0), nullptr_t> = nullptr >
	static void set_modulo(ll mod) { modulo() = mod; }
	void reset_modulo(ll modulus_) { modulo() = modulus_; val %= mod();}
	constexpr modint inv() { return pow(mod() - 2); }
	constexpr ll value() const noexcept { return val; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
	modint &operator+=(const modint rhs) noexcept {
		val += rhs.val;
		if (val >= mod()) {
			val -= mod();
		}
		return *this;
	}
	modint &operator-=(const modint rhs) noexcept {
		if (val < rhs.val) {
			val += mod();
		}
		val -= rhs.val;
		return *this;
	}
	modint &operator*=(const modint rhs) noexcept {
		val = val * rhs.val % mod();
		return *this;
	}
	modint &operator/=(modint rhs) noexcept {
		ll exp = mod() - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
	modint &operator++() noexcept {
		return *this += modint(1);
	}
	modint operator++(int) noexcept {
		modint t = *this;
		*this += modint(1);
		return t;
	}
	modint &operator--() noexcept {
		return *this -= modint(1);
	}
	modint operator--(int) noexcept {
		modint t = *this;
		*this -= modint(1);
		return t;
	}
	constexpr modint operator-() { return val ? mod() - val : val; }
	constexpr bool operator==(const modint rhs) const noexcept { return val == rhs.value(); }
	constexpr bool operator!=(const modint rhs)const  noexcept { return val != rhs.value(); }
	constexpr bool operator <(const modint rhs)const  noexcept { return val < rhs.value(); }
	static constexpr modint zero() { return modint(0); }
	static constexpr modint unit() { return modint(1); }

	modint pow(long long k) const {
		modint v = *this;
		modint res(1), tmp(v);
		while (k) {
			if (k & 1) res *= tmp;
			tmp *= tmp;
			k >>= 1;
		}
		return res;
	}
	
	ll log(modint b) {
		modint val = *this;
		const ll sq = 40000;
		map<modint, ll> dp;
		//dp.reserve(sq);
		modint res(1);
		for (ll r = 0; r < sq; r++) {
			if (!dp.count(res)) dp[res] = r;
			res *= val;
		}
		modint p = val.inv().pow(sq);
		res = b;
		for (ll q = 0; q <= mod() / sq + 1; q++) {
			if (dp.count(res)) {
				ll idx = q * sq + dp[res];
				if (idx > 0) return idx;
			}
			res *= p;
		}
		return INF;
	}
	friend ostream& operator <<(ostream& o, const modint<modulus>& t) {
		o << t.value();
		return o;
	}
	friend istream& operator >>(istream& in, modint<modulus>& t) {
		ll x;
		in >> x;
		t = modint<modulus>(x);
		return in;
	}
	friend modint<modulus> POW(modint<modulus> x, ll n) {
		return modint<modulus>(POW(x.value(), n, mod()));
	}


};
// user defined literal
modint<MOD> operator"" _mod(unsigned long long x) {
	return modint<MOD>(x);
}

template<class T = modint<>>
class Combination {
	// this calculates combination (nCk).
	// Constructor runs in O(MAX).
	// get(n,k) returns nCk in O(1).
	ll N_MAX;
	vector<T> fac, finv;
public:
	Combination(ll N_MAX = 210000)
		: N_MAX(N_MAX), fac(N_MAX), finv(N_MAX){
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		pre_process(2, N_MAX);
	}
	T operator()(ll n, ll k) {
		// choose k from n
		if (N_MAX < n)	pre_process(N_MAX, n);
		if (0<= n && n < k) return 0;
		if (k == 0) return 1;
		if (n < 0) return operator()(-n+k-1, k)* (k%2?-1:0);
		return fac[n] * (finv[k] * finv[n - k]);
	}
	T H(ll n, ll k) {
		// 1) 区間[0, k) を（空を許して）n個に分割する場合の数
		// 2) n個の中からk個を重複を許して選ぶ
		return operator()(n + k - 1, k);
	}
	T P(ll n, ll k) {// n (n-1) ... (n-k+1)
		if (N_MAX < n) pre_process(N_MAX, n);
		return (n<k|| n<0 )? T(0) : fac[n] * finv[n - k];
	}
	T Fac(ll n) { return P(n,n); }
	T FacInv(ll n) { if (N_MAX < n) pre_process(N_MAX, n);  return n < 0 ? T(0) : finv[n]; }
private:
	void pre_process(ll m, ll n) {
		if (N_MAX < n) {
			fac.resize(n); finv.resize(n);
		}
		rep(i, m, n) {
			fac[i] = fac[i - 1] * i;
			finv[i] = finv[i - 1] / i;
		}
	}
};


ll choose(int n, int r) { // O(r) for small n
	ll acc = 1;
	rep(i, 0, r) acc = acc * (n - i) / (i + 1);
	return acc;
}

ll gcd(ll val, ll b) {
	if (val < 0) val *= -1;
	if (b < 0) b *= -1;
	if (val == 0) return b;
	if (b == 0) return val;
	if (val%b == 0) return b;
	else return gcd(b, val%b);
}




vll divisor(ll n) {
	// returns common divisors in O(sqrt(min(n,m)))
	vll res;
	for (ll i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.push_back(i);
			res.push_back(n / i);
		}
		if (i * i == n)res.push_back(i);
	}
	sort(res.begin(), res.end());
	return res;
}

vll divisor(ll n, ll m) {
	// returns common divisors in O(sqrt(min(n,m)))
	if (n > m) swap(n, m);
	vll res;
	for (ll i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			if (m%i == 0) res.push_back(i);
			if (m % (n / i) == 0) res.push_back(n / i);
		}
		if (i * i == n && m % i == 0) res.push_back(i);
	}
	sort(res.begin(), res.end());
	return res;
}

vpll prime_factorize(ll n) {
	// returns prime factorization of n in O(sprt(n))
	vector<pll> res;
	for (ll p = 2; p*p <= n; ++p) {
		if (n%p != 0)continue;
		ll num = 0;
		while (n%p == 0) { ++num; n /= p; }
		res.push_back({ p,num });
	}
	if (n != 1) res.push_back(make_pair(n, 1));
	return res;
}

ll eulers_phi(ll n) {
	// returns the number of coprime integers in O(sqrt(n) + n^(1.4/log log n)) [ the number of prime divisors <= O(log(n^(1.4/log log n) ) ] 
	ll res = 0;
	auto primes = prime_factorize(n);
	ll psize = primes.size();
	rep(bit, 1, 1LL << psize) {
		ll bitsize = popcnt(bit);
		ll arg = (bitsize % 2 ? 1 : -1);
		ll base = 1;
		rep(i, 0, primes.size()) {
			ll p = primes[i].first;
			if(bit &(1LL << i)) 
				base *= p;
		}
		res += arg * (n / base);
	}
	return n - res;
}









template<class T>
T solve_recurrence_relation(const vector<T>& a, const vector<T>& p, ll n) {
	// solve : a[n] = p[0] * a[n-k] + ... + p[k-1] * a[n-1] by calc coefficient (Kitamasa method)
	// a[n] = x[0] * a[0] + x[1] * a[1] + ... + x[k-1] * a[k]

	assert(a.size() == p.size());
	auto k = SZ(p);
	if (n < k) {
		return a[n];
	}
	auto increment = [&](vector<T>& x) {
		x.insert(x.begin(), 0);
		rep(i, 0, k) {
			x[i] += x.back() * p[i];
		}
		x.pop_back();
	};
	auto dbl = [&](vector<T>& x) {
		vector<T> res(k);
		auto x_i = x;
		vector<vector<T>> X(k); 
		X[0] = x_i;
		rep(i, 1, k) {
			increment(x_i);
			X[i] = x_i;
		}
		rep(i, 0, k) {
			rep(j, 0, k) {
				res[i] += x[j] * X[j][i];
			}
		}
		swap(res, x);
	};
	function<void(vector<T>&, ll)> rec = [&](vector<T>& x, ll n) {
		if (n == 0) {
			x.resize(k);
			x[0] = 1;
		}
		else if (n & 1) {
			rec(x, --n);
			increment(x);
		}
		else {
			n /= 2;
			rec(x, n);
			dbl(x);
		}
	};
	vector<T> x;
	rec(x, n);
	T res = 0;
	rep(i, 0, k) {
		res += x[i] * a[i];
	}
	return res;
};







template<class underlying_t = ll, ll max_dim = INF>
class SparsePolynomial
{
public:
	using coeff_t = vector<pair<ll, underlying_t>>;
	coeff_t coeff;

	static void contract(coeff_t& coeff) {
		if (coeff.empty()) return;
		sort_by<0>(coeff);
		auto cur = 0;
		rep(i,1,coeff.size()) {
			if (coeff[cur].first == coeff[i].first) {
				coeff[cur].second += coeff[i].second;
			}
			else {
				++cur;
				coeff[cur] = coeff[i];
			}
		}
		coeff.erase(coeff.begin() + cur + 1, coeff.end());
		reduce(coeff);
	}

	static void reduce(coeff_t& coeff) {
		if (coeff.empty()) return;
		auto cur = 0;
		rep(i, 0, coeff.size()) {
			if (coeff[i].second != 0) {
				coeff[cur] = coeff[i];
				++cur;
			}
		}
		coeff.erase(coeff.begin() + cur, coeff.end());
	}

	SparsePolynomial() : coeff() {}
	SparsePolynomial(int x) : coeff({ { 0, x } }) {}
	explicit SparsePolynomial(const coeff_t& coeff_) : coeff(coeff_) { sort_by<0>(coeff); }
	SparsePolynomial& operator<<=(ll d) {
		coeff_t res;
		for (auto it = coeff.rbegin(); it != coeff.rend(); ++it) {
			if (it->first + d <= max_dim) {
				res.push_back({ it->first + d, it->second });
			}
		}
		coeff = res;
		return *this;
	}
	friend SparsePolynomial operator<<(SparsePolynomial lhs, int rhs) {
		return lhs <<= rhs;
	}
	SparsePolynomial& operator*=(SparsePolynomial rhs) {
		// O(max(coeff.size() * (rhs.coeff.size())^2)
		coeff_t res;
		for(auto& i: coeff) {
			for(auto& j: rhs.coeff) {
				if (i.first + j.first <= max_dim)
					res.emplace_back(i.first + j.first, i.second * j.second);
			}
		}
		swap(coeff, res);
		contract(coeff);
		return *this;
	}
	friend SparsePolynomial operator*(SparsePolynomial lhs, const SparsePolynomial& rhs) {
		return lhs *= rhs;
	}
	SparsePolynomial& operator+=(const SparsePolynomial& rhs) {
		coeff.insert(coeff.end(), rhs.coeff.begin(), rhs.coeff.end());
		contract(coeff);
		return *this;
	}
	friend SparsePolynomial operator+(SparsePolynomial lhs, const SparsePolynomial& rhs) {
		return lhs += rhs;
	}
	bool operator==(const SparsePolynomial& rhs) const {
		return coeff == rhs.coeff;
	}
	underlying_t operator[](ll d) const {
		auto it = lower_bound(all(coeff), pair<ll, underlying_t>({ d, 0 }), [](auto&& l, auto&& r) { return l.first < r.first; });
		if (it != coeff.end() && it->first == d) {
			return it->second;
		}
		else {
			return 0;
		}
	}
};

template<class T = ll, ll max_dim = INF>
struct Polynomial {
	vector<T> a; // coefficients
	Polynomial() = default;
	Polynomial(const vector<T>& coeff) : a(coeff) {}
	Polynomial(ll c) : a{c} {}
	Polynomial(const vector<pair<ll, T>>& coeff) {
		//sort_by<0>(coeff);
		a.resize(coeff.back().first+1);
		rep(i, 0, coeff.size()) {
			a[coeff[i].first] = coeff[i].second;
		}
	}
	Polynomial& operator<<=(ll d) {
		auto n = a.size();
		a.resize(a.size() + d);
		rrep(i, 0, n) {
			a[i + d] = a[i];
		}
		rep(i, 0, d) {
			a[i] = 0;
		}
		return *this;
	}
	friend Polynomial operator<<(Polynomial lhs, int rhs) {
		return lhs <<= rhs;
	}
	Polynomial& operator>>=(ll d) {
		rep(i, 0, a.size() - d) {
			a[i] = a[i+d];
		}
		a.resize(a.size() - d);
		return *this;
	}
	friend Polynomial operator>>(Polynomial lhs, int rhs) {
		return lhs >>= rhs;
	}
	Polynomial& operator*=(Polynomial rhs) {
		auto res = vector<T>(min(SZ(a) + SZ(rhs.a)-1, max_dim+1));
		rep(i, 0, a.size()) {
			if (a[i] == 0)
				continue;
			rep(j, 0, rhs.a.size()) {
				if(i+j <= max_dim)
					res[i + j] += a[i] * rhs.a[j];
			}
		}
		a = res;
		return *this;
	}
	friend Polynomial operator*(Polynomial lhs, const Polynomial& rhs) {
		return lhs *= rhs;
	}
	Polynomial& operator+=(const Polynomial& rhs) {
		a.resize(max(a.size(), rhs.a.size()));
		rep(i, 0, rhs.a.size()) {
			a[i] += rhs.a[i];
		}
		return *this;
	}
	friend Polynomial operator+(Polynomial lhs, const Polynomial& rhs) {
		return lhs += rhs;
	}
	bool operator==(const Polynomial& rhs) const {
		return a == rhs.a;
	}
	function<T(ll)> div(const Polynomial& Q) const {
		// return generating function of rational function q(x)/p(x).
		// O((a.size())^2)
		
		auto q = a;
		auto p = Q.a;
		vector<T> tail;
		auto p0 = p[0];
		p.erase(p.begin());
		if (q.size() <= p.size()) {
			q.resize(p.size());
		}


		rep(i, 0, p.size()) {
			p[i] /= p0;
			p[i] *= -1;
		}
		rep(i, 0, q.size()) {
			q[i] /= p0;
		}
		auto& init = q;
		rep(i, 1, init.size()) {
			rep(j, 1, min(i,SZ(p))+1) {
				init[i] += p[j-1]* init[i-j];
			}
		}
		if (q.size() > p.size()) {
			tail.insert(tail.begin(), q.begin(), q.begin() + q.size() - p.size());
			q.erase(q.begin(), q.begin() + q.size() - p.size());
		}
		reverse(all(p));
		return [tail, init, p](ll n) {
			if (n < tail.size())
				return tail[n];
			else
				return solve_recurrence_relation(init, p, n - tail.size());
		};
	}
};






















int main() {

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	using mod = modint<998244353>;
	using Pol = SparsePolynomial<mod, 3100>;
	ll n, s; cin >> n >> s;
	vll A(n); cin >> A;
	vector<Pol> p(n + 1);
	mod res = 0;
	rep(i, 0, n) {
		p[i + 1] = (p[i] + Pol(1)) * (Pol({ {0,1}, {A[i], 1} }));
		res += p[i + 1][s];

	}

	cout << res << endl;


	return 0;
}

