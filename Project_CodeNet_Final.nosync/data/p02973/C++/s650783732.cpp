#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <complex>
#include <chrono>
#include <random>
#include <numeric>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <climits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <set>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <type_traits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n)-1; i >= 0; i--)
#define inf 0x3f3f3f3f3f3f3f3f
#define ALL(a) (a).begin(), (a).end()
#define DEBUG(x) // cerr<<#x<<": "<<x<<endl
#define ll long long
#define ull unsigned long long
using pii = pair<ll, ll>;
#define eps 1e-14
#define SETUP cin.tie(0), ios::sync_with_stdio(false), cout << setprecision(15) << std::fixed;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template <class T>
using vec2 = std::vector<vector<T>>;

//// bit ////
#ifdef _MSC_VER
#ifdef _WIN32
inline unsigned int __builtin_ctz(unsigned int x) { unsigned long r; _BitScanForward(&r, x); return r; }
inline unsigned int __builtin_clz(unsigned int x) { unsigned long r; _BitScanReverse(&r, x); return 31 - r; }
inline unsigned int __builtin_ffs(unsigned int x) { unsigned long r; return _BitScanForward(&r, x) ? r + 1 : 0; }
// inline unsigned int __builtin_popcount(unsigned int x){ return __popcnt(x); }
#ifdef _WIN64
inline unsigned long long __builtin_ctzll(unsigned long long x) { unsigned long r; _BitScanForward64(&r, x); return r; }
inline unsigned long long __builtin_clzll(unsigned long long x) { unsigned long r; _BitScanReverse64(&r, x); return 63 - r; }
inline unsigned long long __builtin_ffsll(unsigned long long x) { unsigned long r; return _BitScanForward64(&r, x) ? r + 1 : 0; }
inline unsigned long long __builtin_popcountll(unsigned long long x) { return __popcnt64(x); }
#else
inline unsigned int hidword(unsigned long long x) { return static_cast<unsigned int>(x >> 32); }
inline unsigned int lodword(unsigned long long x) { return static_cast<unsigned int>(x & 0xFFFFFFFF); }
inline unsigned long long __builtin_ctzll(unsigned long long x) { return lodword(x) ? __builtin_ctz(lodword(x)) : __builtin_ctz(hidword(x)) + 32; }
inline unsigned long long __builtin_clzll(unsigned long long x) { return hidword(x) ? __builtin_clz(hidword(x)) : __builtin_clz(lodword(x)) + 32; }
inline unsigned long long __builtin_ffsll(unsigned long long x) { return lodword(x) ? __builtin_ffs(lodword(x)) : hidword(x) ? __builtin_ffs(hidword(x)) + 32 : 0; }
// inline unsigned long long __builtin_popcountll(unsigned long long x) { return __builtin_popcount(lodword(x)) + __builtin_popcount(hidword(x)); }
#endif // _WIN64
#endif // _WIN32
#endif // _MSC_VER

namespace
{
	struct input_returnner
	{
		ll N;
		input_returnner(ll N_ = 0) : N(N_) {}
		template <typename T>
		operator vector<T>() const
		{
			vector<T> res(N);
			for (auto& a : res)
				cin >> a;
			return std::move(res);
		}
		template <typename T>
		operator T() const
		{
			T res;
			cin >> res;
			return res;
		}
		template <typename T>
		T operator-(T right) { return T(input_returnner()) - right; }
		template <typename T>
		T operator+(T right) { return T(input_returnner()) + right; }
		template <typename T>
		T operator*(T right) { return T(input_returnner()) * right; }
		template <typename T>
		T operator/(T right) { return T(input_returnner()) / right; }
		template <typename T>
		T operator<<(T right) { return T(input_returnner()) << right; }
		template <typename T>
		T operator>>(T right) { return T(input_returnner()) >> right; }
	};
	template <typename T>
	input_returnner in() { return in<T>(); }
	input_returnner in() { return input_returnner(); }
	input_returnner in(ll N) { return std::move(input_returnner(N)); }
} // namespace

template <typename T>
istream& operator>>(istream& is, vector<T>& vec)
{
	for (T& x : vec)
		is >> x;
	return is;
}

template <typename T>
struct is_vector : std::false_type
{
};

template <typename T>
struct is_vector<std::vector<T>> : std::true_type
{
};

template <typename T>
constexpr bool is_vector_v = is_vector<T>::value;

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
	if (!v.empty())
	{
		for (int i = 0; i < v.size(); ++i)
		{
			out << v[i] << (i == v.size() - 1 ? "\n" : (is_vector_v<T> ? "" : ", "));
		}
	}
	return out;
}

namespace std
{
	// ref: https://stackoverflow.com/questions/7110301/generic-hash-for-tuples-in-unordered-map-unordered-set
	template <class T>
	inline void hash_combine(std::size_t& seed, T const& v)
	{
		seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
	}

	// Recursive template code derived from Matthieu M.
	template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
	struct HashValueImpl
	{
		static void apply(size_t& seed, Tuple const& tuple)
		{
			HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
			hash_combine(seed, std::get<Index>(tuple));
		}
	};

	template <class Tuple>
	struct HashValueImpl<Tuple, 0>
	{
		static void apply(size_t& seed, Tuple const& tuple)
		{
			hash_combine(seed, std::get<0>(tuple));
		}
	};
	template <typename... TT>
	struct hash<std::tuple<TT...>>
	{
		size_t operator()(std::tuple<TT...> const& tt) const
		{
			size_t seed = 0;
			HashValueImpl<std::tuple<TT...>>::apply(seed, tt);
			return seed;
		}
	};

	template <class T, class U>
	class hash<std::pair<T, U>>
	{
	public:
		size_t operator()(const std::pair<T, U>& x) const
		{
			return hash<std::tuple<T, U>>()(std::tie(x.first, x.second));
		}
	};
} // namespace std

// ref: https://stackoverflow.com/questions/6245735/pretty-print-stdtuple
namespace aux
{
	template <std::size_t...>
	struct seq
	{
	};

	template <std::size_t N, std::size_t... Is>
	struct gen_seq : gen_seq<N - 1, N - 1, Is...>
	{
	};

	template <std::size_t... Is>
	struct gen_seq<0, Is...> : seq<Is...>
	{
	};

	template <class Ch, class Tr, class Tuple, std::size_t... Is>
	void print_tuple(std::basic_ostream<Ch, Tr>& os, Tuple const& t, seq<Is...>)
	{
		using swallow = int[];
		(void)swallow {
			0, (void(os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), 0)...
		};
	}
} // namespace aux

template <class Ch, class Tr, class... Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t)
-> std::basic_ostream<Ch, Tr> &
{
	os << "(";
	aux::print_tuple(os, t, aux::gen_seq<sizeof...(Args)>());
	return os << ")";
}

template <class S, class T>
std::ostream& operator<<(std::ostream& os, const std::pair<S, T>& p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

// ref: https://stackoverflow.com/questions/8542591/c11-reverse-range-based-for-loo�Fp
template <typename T>
struct reversion_wrapper
{
	T& iterable;
};

template <typename T>
auto begin(reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end(reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> REV(T&& iterable) { return { iterable }; }

template <class T>
bool inside(T left, T val, T right)
{
	return left <= val and val < right;
}

template <class T>
T bitCount(T num)
{
	T res = 0;
	while (num > 0)
	{
		if (num & 1)
			++res;
		num >>= 1;
	}
	return res;
}

ll MOD = 1e9 + 7;
//ll MOD = 998244353;

void solve();

signed main()
{
	SETUP;
#ifdef _DEBUG
	while (true)
	{
#endif
		solve();
#ifdef _DEBUG
		cout << "-------" << endl;
	}
#endif
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}

#define int ll

struct mint {
	int64_t value;
	mint() :value(0) {}
	mint(int64_t value_) : value(value_% MOD) {}
	inline mint& operator += (const mint& rhs) {
		value += rhs.value;
		if (value >= MOD) { value -= MOD; }
		return *this;
	}
	inline mint& operator -= (const mint& rhs) {
		value -= rhs.value;
		if (value < 0) {
			value += MOD;
		}
		return *this;
	}
	inline mint& operator *= (const mint& rhs) {
		value *= rhs.value;
		value %= MOD;
		return *this;
	}
	inline mint& operator %= (const mint& rhs) {
		return *this;
	}
};

// x^n % mod
// O(log n)
mint mod_pow(mint x, uint64_t n) {
	mint res = 1;
	while (n > 0) {
		if (n & 1) res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

string bin(int x) {
	string res = "";
	RREP(i, 32) {
		res += ((x >> i) & 1) ? "1" : "0";
	}
	return res;
}

inline mint operator + (const mint& lhs, const mint& rhs) { mint res = lhs; res += rhs; return res; }
inline mint operator - (const mint& lhs, const mint& rhs) { mint res = lhs;	res -= rhs;	return res; }
inline mint operator * (const mint& lhs, const mint& rhs) { mint res = lhs;	res *= rhs;	return res; }
inline mint operator % (const mint& lhs, const uint64_t& rhs) { return lhs; }

ostream& operator << (ostream& out, mint n) { return out << n.value; }

class prime {
private:
public:
	std::vector<int> primes;
	std::vector<bool> isPrime;
	prime(int num = 0) {
		if (num == 0) return;
		isPrime.resize(num + 1);
		fill(isPrime.begin(), isPrime.end(), true);
		int ma = sqrt(num) + 1;
		isPrime[0] = isPrime[1] = false;
		int cnt = 0;
		for (int i = 2; i <= ma; ++i) if (isPrime[i]) {
			for (int j = 2; i * j <= num; ++j) {
				isPrime[i * j] = false;
				cnt++;
			}
		}
		primes.reserve(cnt);
		for (int i = 0; i < isPrime.size(); ++i) if (isPrime[i]) {
			primes.push_back(i);
		}
	}

	bool IsPrime(int num) {
		if (num < isPrime.size()) return isPrime[num];
		for (auto p : primes) {
			if (num % p == 0) return false;
		}
		int ma = sqrt(num) + 1;
		for (int i = primes.back(); i <= ma; i += 2) {
			if (num % i == 0) return false;
		}
		return true;
	}

	std::map<int, int> GetFactor(int num) {
		std::map<int, int> res;
		int a = 2;
		auto it = primes.begin();
		while (num >= a * a) {
			if (num % a == 0) {
				res[a]++;
				num /= a;
			}
			else {
				++it;
				if (it == primes.end()) {
					break;
				}
				a = *it;
			}
		}
		res[num]++;
		return res;
	}
};

int gcd(int a, int b) {
	return b != 0 ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

// a x + b y = gcd(a, b)
int extgcd(int a, int b, int& x, int& y) {
	int g = a; x = 1; y = 0;
	if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
	return g;
}

inline long long mod(long long a, long long m) {
	return (a % m + m) % m;
}

// condition: gcd(a,m) == 1
long long modinv(long long a, long long m) {
	long long x, y;
	extgcd(a, m, x, y);
	return mod(x, m);
}

void solve() {
	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a;

	map<int, int> memo;
	memo[-1] = 1;

	for (auto& a : A) {
		auto it = memo.lower_bound(a);
		--it;
		if (it->first == -1) {
			memo[a] += 1;
		}
		else {
			memo[it->first]--;
			memo[a]++;
			if (memo[it->first] == 0) {
				memo.erase(it->first);
			}
		}
	}
	int res = 0;
	for (auto& a : memo) {
		res += a.second;
	}
	cout << res-1 << endl;
}
