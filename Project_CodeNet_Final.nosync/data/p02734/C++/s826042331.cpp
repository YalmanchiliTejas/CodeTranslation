#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

// [a -> b-1]
#define reps(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
// [0 -> a-1]
#define rep(i, a) reps(i, 0, (a))
// [a-1 -> b]
#define rreps(i, a, b) for (int i = (int)((a)-1); i >= (int)(b); i--)
// [a-1 -> 0]
#define rrep(i, a) rreps(i, a, 0)
#define all(v) (v).begin(), (v).end()
// next_permutation(all(v))
#define PERM(v) next_permutation(all(v))
/*sort(all(v));
 * (v).erase(unique(all(v)), v.end())*/
#define UNIQUE(v)\
	sort(all(v));\
	(v).erase(unique(all(v)), v.end())
// b is [a, c)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
// c is [a, e) && d is [b, f)
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmax(a, b) a = max(a, (b))
#define fcout cout << fixed << setprecision(15)
#define YES(f) cout << ((f) ? YES_STR : NO_STR) << endl;

#ifdef LOCAL_DEBUG_OPTION
namespace debug_print_n{
struct DebugPrint {
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_integral<U>::value && !is_same<U, bool>::value && !is_same<U, char>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << x;
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, bool>::value> DUMP_SUB_FUNCTION(T x) {
		if (x) cerr << "True";
		else cerr << "False";
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, char>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << '\'' << x << '\'';
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_same<U, string>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << '\"' << x << '\"';
	}
	template<class T>
	static enable_if_t<is_same<T, const char*>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << string(x);
	}
	template<class T>
	static enable_if_t<true> DUMP_SUB_FUNCTION(vector<T> x) {
		cerr << '{';
		for (size_t i = 0; i < x.size(); i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(x[i]);
		}
		cerr << '}';
	}
	template<class T, size_t N>
	static enable_if_t<true> DUMP_SUB_FUNCTION(array<T, N> x) {
		cerr << '{';
		for (size_t i = 0; i < x.size(); i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(x[i]);
		}
		cerr << '}';
	}
	template<class T>
	static enable_if_t<true> DUMP_SUB_FUNCTION(set<T> x) {
		cerr << '[';
		size_t i = 0;
		for (auto itr = x.begin(); itr != x.end(); itr++, i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(*itr);
		}
		cerr << ']';
	}
	template<class T, class U>
	static enable_if_t<true> DUMP_SUB_FUNCTION(map<T, U> x) {
		cerr << '[';
		size_t i = 0;
		for (auto itr = x.begin(); itr != x.end(); itr++, i++) {
			if (i) cerr << ", ";
			DUMP_SUB_FUNCTION(itr->first);
			cerr << " : ";
			DUMP_SUB_FUNCTION(itr->second);
		}
		cerr << ']';
	}
	template<class T, class U = remove_const_t<remove_reference_t<T>>>
	static enable_if_t<is_floating_point<U>::value> DUMP_SUB_FUNCTION(T x) {
		cerr << fixed << setprecision(5) << x;
	}
	template<class T, class U>
	static enable_if_t<true> DUMP_SUB_FUNCTION(pair<T, U> p) {
		cerr << '(';
		DUMP_SUB_FUNCTION(p.first);
		cerr << ", ";
		DUMP_SUB_FUNCTION(p.second);
		cerr << ')';
	}
	template<int num = 0, class... Args>
	static enable_if_t<num == sizeof...(Args)> DUMP_SUB_FUNCTION(tuple<Args...> t) {
		if (num) cerr << ')';
	}
	template<int num = 0, class... Args>
	static enable_if_t<num < sizeof...(Args)> DUMP_SUB_FUNCTION(tuple<Args...> t) {
		if (num == 0) cerr << '(';
		DUMP_SUB_FUNCTION(get<num>(t));
		if (num + 1 < sizeof...(Args)) cerr << ", ";
		DUMP_SUB_FUNCTION<num+1>(t);
	}
	template<long unsigned N>
	static enable_if_t<true> DUMP_SUB_FUNCTION(bitset<N> x) {
		cerr << x;
	}
};
void dump() {
	cerr << endl;
}
template<class Head, class... Tail>
void dump(Head&& head, Tail&&... tail) {
	DebugPrint::DUMP_SUB_FUNCTION(head);
	if (sizeof...(Tail) != 0) {
		cerr << ' ';
	}
	dump(forward<Tail>(tail)...);
}
} // namespace debug_print_n
using debug_print_n::dump;
#else
template<class... Args> void dump(Args&&... args) { }
#endif

namespace bit {
using u32 = uint_fast32_t;
using u64 = unsigned long long;
template<class T>
constexpr T set(T bin, u32 pos) {
	return bin | (1ull << pos);
}
template<class T>
constexpr T unset(T bin, u32 pos) {
	return bin & ~(1ull << pos);
}
template<class T>
constexpr T get(T bin, u32 pos) {
	return bin & (1ull << pos);
}
template<class T>
constexpr bool check(T bin, u32 pos) {
	return get(bin, pos);
}
constexpr u32 popcount(u64 bin) {
	return __builtin_popcountll(bin);
}
} // namespace bit

constexpr long long MOD = 998244353;
/**
 * @title ModInt
 * @brief mod を取りながら計算する。リテラル型の要件を満たし、constexprに対応している。
 * @brief これでも Verify してます。 https://github.com/spihill/library/blob/master/test/mytest/ModInt.test.cpp
 */
namespace modint_n {
using value_type = signed;
template<value_type mod>
struct ModInt {
	using i64 = int_fast64_t;
	value_type x;
	constexpr static value_type get_mod() {
		return mod;
	}
	constexpr ModInt(i64 x_) : x(mod_(x_)) {}
	constexpr ModInt() : ModInt(0) {}
	~ModInt() = default;
	inline constexpr ModInt& operator+=(const ModInt rhs) {
		i64 t = static_cast<i64>(x) + rhs.x;
		if (t >= mod) x = t - mod;
		else x = t;
		return (*this);
	}
	inline constexpr ModInt& operator-=(const ModInt rhs) {
		i64 t = static_cast<i64>(x) + mod - rhs.x;
		if (t >= mod) x = t - mod;
		else x = t;
		return *this;
	}
	inline constexpr ModInt& operator*=(const ModInt rhs) {
		x = static_cast<i64>(x) * rhs.x % mod;
		return *this;
	}
	inline constexpr ModInt& operator/=(ModInt rhs) {
		return *this *= rhs.inv();
	}
	inline constexpr ModInt power(i64 p) const {
		ModInt res = 1;
		ModInt a = x;
		for (; p; res = p & 1 ? res * a : res, a *= a, p >>= 1);
		return res;
	}
	inline constexpr ModInt inv() const {
		value_type z = 0, w = 0;
		extgcd(mod, x, z, w);
		return ModInt(w);
	}
	inline constexpr ModInt& operator=(const ModInt& rhs) {
		this->x = rhs.x;
		return *this;
	}
	inline constexpr value_type operator==(const ModInt& rhs) const {
		return this->x == rhs.x;
	}
	inline constexpr value_type operator!=(const ModInt& rhs) const {
		return !(*this == rhs);
	}
	inline constexpr ModInt operator++(signed unused) {
		ModInt res(*this);
		++(*this);
		return res;
	}
	inline constexpr ModInt& operator++() {
		(*this) += 1;
		return (*this);
	}
	inline constexpr ModInt operator--(signed unused) {
		ModInt res(*this);
		--(*this);
		return res;
	}
	inline constexpr ModInt& operator--() {
		(*this) -= 1;
		return (*this);
	}
	inline constexpr ModInt operator+() const {
		return (*this);
	}
	inline constexpr ModInt operator-() const {
		return (*this).x ? ModInt(mod - (*this).x) : ModInt(0);
	}
	friend constexpr ModInt operator+(const ModInt& lhs, const ModInt& rhs) {return ModInt(lhs) += rhs;}
	friend constexpr ModInt operator-(const ModInt& lhs, const ModInt& rhs) {return ModInt(lhs) -= rhs;}
	friend constexpr ModInt operator*(const ModInt& lhs, const ModInt& rhs) {return ModInt(lhs) *= rhs;}
	friend constexpr ModInt operator/(const ModInt& lhs, const ModInt& rhs) {return ModInt(lhs) /= rhs;}
	explicit constexpr operator value_type() const {return x;}
	friend ostream& operator<<(ostream& lhs, const ModInt& rhs) {
		lhs << rhs.x;
		return lhs;
	}
	friend istream& operator>>(istream& lhs, ModInt& rhs) {
		i64 t;
		lhs >> t;
		rhs = ModInt(t);
		return lhs;
	}
private:
	constexpr value_type extgcd(value_type a, value_type b, value_type& x, value_type& y) const {
		value_type d = a;
		if (b == 0) {
			x = 1;
			y = 0;
		} else {
			d = extgcd(b, a%b, y, x);
			y -= a / b * x;
		}
		return d;
	}
	constexpr value_type mod_(i64 x) {
		x %= mod; if (x < 0) x += mod;
		return static_cast<value_type>(x);
	}
};
}; // modint_n
using modint_n::ModInt;
namespace std {
template<modint_n::value_type N> struct is_integral<ModInt<N>> {
	static constexpr integral_constant<bool, true> value = integral_constant<bool, true>();
};
template<modint_n::value_type N> struct is_arithmetic<ModInt<N>> {
	static constexpr integral_constant<bool, true> value = integral_constant<bool, true>();
};
template<modint_n::value_type N> struct is_scalar<ModInt<N>> {
	static constexpr integral_constant<bool, true> value = integral_constant<bool, true>();
};
template<modint_n::value_type N> struct is_floating_point<ModInt<N>> {
	static constexpr integral_constant<bool, false> value = integral_constant<bool, false>();
};
template<modint_n::value_type N> struct is_signed<ModInt<N>> {
	static constexpr integral_constant<bool, false> value = integral_constant<bool, false>();
};
template<modint_n::value_type N> struct is_unsigned<ModInt<N>> {
	static constexpr integral_constant<bool, true> value = integral_constant<bool, true>();
};
} // namespace std
//using modint = ModInt<1000000007>;
using modint = ModInt<998244353>;

using poly = array<modint, 3001>;

poly f(const poly& a, int b) {
	poly res = a;
	reps(i, b, 3001) {
		res[i] += a[i-b];
	}
	return res;
}

signed main(){
	poly res;
	modint sum = 0;
	fill(all(res), 0);
	int n, s; cin >> n >> s;
	while (n--) {
		int x; cin >> x;
		res[0]++;
		res = f(res, x);
		sum += res[s];
	}
	cout << sum << endl;
	return 0;
}
