#pragma region header
#include <bits/stdc++.h>
using namespace std;

#define CPP_CAT(x,y) CPP_CAT_I(x,y)
#define CPP_CAT_I(x,y) x ## y
//#define CPP_STR(x) CPP_STR_I(x)
//#define CPP_STR_I(args...) #args
//#define ASSERT(expr...) assert((expr))

using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f32 = float;
using f64 = double;
//using f80 = __float80;

constexpr i64 INF = 1'010'000'000'000'000'017LL;
constexpr i64 MOD = 1'000'000'007LL;
constexpr f64 EPS = 1e-12;
constexpr f64 PI = 3.14159265358979323846;
constexpr char EL[] = "\n";

#define FOR(i, start, end) for(i64 i = (start), CPP_CAT(i,xxxx_end)=(end); i < CPP_CAT(i,xxxx_end); ++i)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(),(x).end()
#define ALL(f,c,...) (([&](decltype((c)) cccc) { return (f)(std::begin(cccc), std::end(cccc), ## __VA_ARGS__); })(c))
#define UNIQUE(x) (x).erase(unique(all(x)), (x).end());
#define REPIT(x) for(auto it=(x).begin(), end=(x).end(); it!=end; ++it)
#define perm(c) sort(all(c)); for(bool c##p=1;c##p;c##p=next_permutation(all(c)))

template<typename T = i64>
T IN() { T x; cin >> x; return (x); }

template<typename C>
i64 SIZE(const C& c) { return static_cast<i64>(c.size()); }
template<typename T, size_t N>
i64 SIZE(const T(&)[N]) { return static_cast<i64>(N); }

template<typename T, typename U, typename Comp = less<>>
bool chmax(T& xmax, const U& x, Comp comp = {}) {
	if (comp(xmax, x)) {
		xmax = x;
		return true;
	}
	return false;
}
template<typename T, typename U, typename Comp = less<>>
bool chmin(T& xmin, const U& x, Comp comp = {}) {
	if (comp(x, xmin)) {
		xmin = x;
		return true;
	}
	return false;
}

void print() {
  cout << EL;
}
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
}
template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
	cout << a;
	if (&a != &vec.back()) cout << " ";
  }
  cout << EL;
}
template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
	print(vec);
  }
}

struct ProconInit {
	static constexpr int IOS_PREC = 15;
	static constexpr bool AUTOFLUSH = false;

	ProconInit() {
		cin.tie(nullptr);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(IOS_PREC);
		if (AUTOFLUSH)
			cout << unitbuf;
	}
} PROCON_INIT;
#pragma endregion

signed solve()
{
	char c;
	cin >> c;
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		print("vowel");
	else
		print("consonant");
	return 0;
}

#ifndef LOCALCODE
signed main()
{
	return solve();
}
#endif
