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
		TM_(Sep, class F, class... Ts) static ostream &print(ostream &os, Sep sep, F const &f, Ts const &... ts) { return void(initializer_list<int>{(out_(os, f, 0), 0), (out_(os << sep, ts, 0), 0)...}), os; }
		TM_(T) static auto in_(istream &is, T &t, int) -> decltype(void(is >> t)) { is >> t; }
		TM_(T, class IS) static auto in_(IS &is, T &t, int) -> decltype(void(begin(t))) { for (auto &x : t) in_(is, x, 0); }
		TM_(T, size_t... Is) static void in_tup(istream &is, T &t, index_sequence<Is...>) { (void)initializer_list<int>{0, (in_(is, get<Is>(t), 0), 0)...}; }
		TM_(T) static decltype(void(TupSz<T>{})) in_(istream &is, T &t, char) { in_tup(is, t, make_index_sequence<TupSz<T>::value>{}); }
	};
	} // namespace narut
	#define Cout(...) narut::IO::print(cout, ' ', __VA_ARGS__) << '\n'
	#ifdef NARUT_LOCAL
	#define Debug(...) narut::IO::print(cerr << "\033[0;31m", ", ", __VA_ARGS__) << "\033[0m\n"
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

// clang-format on



constexpr ll Inf = 0x3f3f3f3f3f3f3f3f;

auto Main() {
	int n;
	cin>>n;
	vector<int> A(n);
	Cin>>A;

	array<ll, 3> fi{-Inf, -Inf, -Inf};
	array<ll, 3> fr{-Inf, 0, -Inf};

	FOR(i,0,n) {
		auto ix = [j=i/2]( const auto& A, int m) {
			if(m==j-1) return A[0];
			if(m==j) return A[1];
			if (m==j+1) return A[2];
			return -Inf;
		};

		int a = A[i];
		int hf = (i+1)/2;
		array<ll,3>  tfi{
			ix(fr, hf-2) + a,
			ix(fr, hf-1) + a,
			ix(fr, hf) + a
		};
		array<ll, 3> tfr{
			max(ix(fi,hf-1), ix(fr, hf-1)),
			max(ix(fi,hf), ix(fr, hf)),
			max(ix(fi,hf+1), ix(fr, hf+1))
		};
		
		fi = tfi;
		fr = tfr;
	}
	cout << max(fi[1], fr[1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(10);
#ifdef NARUT_LOCAL
	assert(freopen("io/test.in", "r", stdin));
	cin.exceptions(cin.badbit | cin.failbit);
	cerr << fixed << setprecision(10);
#endif

	Main();
}
