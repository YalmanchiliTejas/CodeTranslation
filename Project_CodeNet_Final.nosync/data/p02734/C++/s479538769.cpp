// clang-format off
	#define BADSEED random_device{}()
	#include <bits/stdc++.h>
	using namespace std;
	using ll = long long;
	using uint = unsigned int;
	ostream &operator<<(ostream &os, int8_t c) { return os << short(c); }
	istream &operator>>(istream &is, int8_t &c) { short x; is >> x; c = x; return is; }
	#define TM_(...) template <class __VA_ARGS__>
	namespace narut {
	TM_(T) using TupSz = tuple_size<decay_t<T>>;
	TM_(T) constexpr auto spc(T const &t, int) -> decltype((cout << t), 'a') { return ' '; }
	constexpr auto spc(string const &s, int) { return '\n'; }
	TM_(T) constexpr auto spc(T const &t, char) { return '\n'; }
	struct IO {
		TM_(T) static auto out_(ostream &os, T const &t, int) -> decltype(void(os << t)) { os << t; }
		TM_(T, class OS) static auto out_(OS &os, T const &t, int) -> decltype(void(begin(t))) {
			auto it = begin(t), e = end(t);
			if (it != e) out_(os, *it++, 0);
			for (; it != e; out_(os, *it++, 0)) os << spc(*it, 0);
		}
		TM_(T, size_t... Is) static void out_tup(ostream &os, T const &t, index_sequence<Is...>) { (void)initializer_list<int>{0, ((Is == 0) ? 0 : ((os << ' '), 0), (os << get<Is>(t)), 0)...}; }
		TM_(T) static decltype(void(TupSz<T>{})) out_(ostream &os, T const &t, char) { out_tup(os, t, make_index_sequence<TupSz<T>::value>{}); }
		TM_(Sep, class F, class... Ts) static ostream &print(ostream &os, Sep sep, F const &f, Ts const &... ts) { return void(initializer_list<int>{(out_(os, f, 0), 0), (out_(os << sep, ts, 0), 0)..., (os << '\n', 0)}), os; }
		TM_(T) static auto in_(istream &is, T &t, int) -> decltype(void(is >> t)) { is >> t; }
		TM_(T, class IS) static auto in_(IS &is, T &t, int) -> decltype(void(begin(t))) { for (auto &x : t) in_(is, x, 0); }
		TM_(T, size_t... Is) static void in_tup(istream &is, T &t, index_sequence<Is...>) { (void)initializer_list<int>{0, (in_(is, get<Is>(t), 0), 0)...}; }
		TM_(T) static decltype(void(TupSz<T>{})) in_(istream &is, T &t, char) { in_tup(is, t, make_index_sequence<TupSz<T>::value>{}); }
	};
	} // namespace narut
	#define Cout(...) narut::IO::print(cout, ' ', __VA_ARGS__);
	#ifdef NARUT_LOCAL
	#define Debug(...) narut::IO::print(cerr << "\033[0;31m", ", ", __VA_ARGS__) << "\033[0m"
	#else
	#define Debug(...) 0
	#endif
	[[maybe_unused]] struct Cin {
		template <class T> Cin const &operator>>(T &t) const { return narut::IO::in_(cin, t, 0), *this; }
		template <class T> operator T() const { T t; return *this >> t, t;  }
	} Cin;
	TM_(T) auto operator%(T &t, size_t n) -> decltype(t.resize(n), t)& { return t.resize(n), t; }
	#define FOR(i, j, n) for (int i = int(j); i < int(n); ++i)
	#define ROF(i, j, n) for (int i = int(n) - 1; i >= int(j); --i)
	#define Lx(...) [&](auto &&x) { return __VA_ARGS__; }
	#define Lxy(...) [&](auto &&x, auto &&y) { return __VA_ARGS__; }

// clang-format on



template <class T, class AddT, class MultT, T P> struct ModNum {
	using value_type = T;
	using add_type = AddT;
	using mult_type = MultT;
	static constexpr T mod_value = P;

	T val = 0;
	constexpr ModNum() = default;
	constexpr ModNum(T x) : val(x) {}
	template <class S> static constexpr ModNum Safe(S x) {
		return static_cast<T>(((x % P) + P) % P);
	}
	explicit constexpr operator value_type const &() const { return val; }

	constexpr bool operator==(ModNum rhs) const { return val == rhs.val; }
	constexpr bool operator!=(ModNum rhs) const { return val != rhs.val; }
	constexpr ModNum operator-() const { return (val == 0) ? (*this) : (P - val); }

	constexpr ModNum &operator+=(ModNum rhs) { return *this = Add(val, rhs.val); }
	constexpr ModNum &operator-=(ModNum rhs) { return *this = Sub(val, rhs.val); }
	constexpr ModNum &operator*=(ModNum rhs) { return *this = Mult(val, rhs.val); }
	constexpr ModNum &operator/=(ModNum rhs) { return *this *= rhs.Inverse(); }

	template <class S> constexpr ModNum Pow(S ex) const {
		if (P == 1) return 0;
		if (ex < 0) return Pow(-ex).Inverse();
		ModNum result = 1;
		ModNum base(*this);
		while (ex > 0) {
			if (ex & 1) result *= base;
			ex >>= 1;
			base *= base;
		}
		return result;
	}
	constexpr ModNum Inverse() const { return Pow(P - 2); }
	friend constexpr ModNum operator+(ModNum lhs, ModNum rhs) { return Add(lhs.val, rhs.val); }
	friend constexpr ModNum operator-(ModNum lhs, ModNum rhs) { return Sub(lhs.val, rhs.val); }
	friend constexpr ModNum operator*(ModNum lhs, ModNum rhs) { return Mult(lhs.val, rhs.val); }
	friend constexpr ModNum operator/(ModNum lhs, ModNum rhs) { return lhs * rhs.Inverse(); }

  private:
	static constexpr T Add(AddT lhs, AddT rhs) {
		auto sum = lhs + rhs;
		return (sum < P) ? sum : (sum - P);
	}
	static constexpr T Sub(AddT lhs, AddT rhs) {
		auto dif = lhs - rhs;
		return (dif >= 0) ? dif : (dif + P);
	}
	static constexpr T Mult(MultT lhs, MultT rhs) { return static_cast<T>((lhs * rhs) % P); }
	friend ostream &operator<<(ostream &os, ModNum m) { return os << m.val; }
	friend istream &operator>>(istream &is, ModNum &m) {
		is >> m.val;
		return is;
	}
};
using Num = ModNum<int, int, int64_t, 998244353>;


int n,s;
vector<int> A;

auto Run() {
	cin>>n>>s;
	Cin>>A%n;

	Num ans = 0;
	vector<Num> dp(s);
	FOR(i,0,n) {
		dp[0] = i+1;
		int a = A[i];
		if (s - a < 0) continue;
		
			ans += dp[s-a] * (n-i);
		
		ROF(j,1,s) {
			if (j-a < 0) break;
			dp[j] += dp[j-a];
		}						
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(10);
#ifdef NARUT_LOCAL
	cin.exceptions(cin.failbit);
	cerr << fixed << setprecision(10);
	assert(freopen("./io/test.in", "r", stdin));
	// assert(freopen("./io/test.out", "w", stdout));
#endif

	Run();
}
