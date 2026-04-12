
#pragma GCC optimize ("-O3")
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



//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//using lll = mp::cpp_int;

using namespace std;

using ll = long long;
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
template<class T>
constexpr bool exist(const vector<T>& container, const T& val) { return find(all(container), val) != container.end(); }
template<class T>
constexpr bool exist(const set<T>& container, const T& val) { return container.find(val) != container.end(); }
template<class T, class S>
constexpr bool exist(const map<T,S>& container, const T& val) { return container.find(val) != container.end(); }

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
		: N_MAX(2), fac(2,1), finv(2,1){
		pre_process(N_MAX);
	}
	T operator()(ll n, ll k) {
		// choose k from n
		pre_process(n);
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
		pre_process(n);
		return (n<k|| n<0 )? T(0) : fac[n] * finv[n - k];
	}
	T Fac(ll n) { return P(n,n); }
	T FacInv(ll n) { pre_process(n);  return n < 0 ? T(0) : finv[n]; }
private:
	void pre_process(ll n) {
		if (n <= N_MAX) return;
		ll next = N_MAX;
		while (next <= n) next <<= 1;
		fac.resize(next); finv.resize(next);
		rep(i, N_MAX, next) {
			fac[i] = fac[i - 1] * i;
			finv[i] = finv[i - 1] / i;
		}
		N_MAX = next;
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



























int main() {

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	ll n; cin >> n;
	vll a(n); cin >> a;
	using mod = modint<>;
	mod x = 0;
	rep(i, 0, n) {
		x += a[i];
	}
	mod y = x * x;
	rep(i, 0, n) {
		y -= a[i] * a[i];
	}
	cout << y / 2 << endl;

	return 0;
}


