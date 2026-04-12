////////////////////////////////////////
///  tu3 pro-con template            ///
////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;

// -- typedefs -- //
#define EPS 1e-9
typedef long long llong;

// -- loop macros -- //
#define LOOP_TYPE(s,n) std::remove_reference_t<std::remove_cv_t<decltype((n)-(s))>>
#define FOR(i,s,n)  for (auto i = LOOP_TYPE(s,n)(s);   i < LOOP_TYPE(s,n)(n);   i++)
#define FORR(i,s,n) for (auto i = LOOP_TYPE(s,n)(n)-1; i != LOOP_TYPE(s,n)(s)-1; i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) FORR(i,0,n)

#define FORE(exp) for (auto && exp)
#define allof(c) c.begin(), c.end()
#define partof(c,s,e) c.begin() + (s), c.begin() + (e)

// -- functors -- //
#define PREDICATE(t,a,...) [&](const t & a) -> bool { return __VA_ARGS__; }
#define PRED(a,...) PREDICATE(auto,a,__VA_ARGS__)
#define COMPARISON(t,a,b,...) [&](const t & a, const t & b) -> bool { return __VA_ARGS__; }
#define COMP(a,b,...) COMPARISON(auto,a,b,__VA_ARGS__)
#define CONV1(a,...) [&](const auto & a) -> auto { return __VA_ARGS__; }
#define CONV2(a,b,...) [&](const auto & a, const auto & b) -> auto { return __VA_ARGS__; }
#define CONV3(a,b,c,...) [&](const auto & a, const auto & b, const auto & c) -> auto { return __VA_ARGS__; }

#define TIE(...) auto tie() const { return std::tie(__VA_ARGS__); }
#define LESS(t) bool operator <(const t &rhs) const { return tie() < rhs.tie(); }
#define GREATER(t) bool operator >(const t &rhs) const { return tie() > rhs.tie(); }

// -- I/O Helper -- //
struct _Reader { istream& cin; template <class T> _Reader operator ,(T& rhs) { cin >> rhs; return *this; } };
struct _Writer { ostream& cout; const char* d{ " " }; bool f{}; template <class T> _Writer operator ,(const T& rhs) { cout << (f ? d : "") << rhs; f = 1; return *this; } };
#define READ(t,...) t __VA_ARGS__; (_Reader{cin}), __VA_ARGS__
#define WRITE(...) do { (_Writer{cout}), __VA_ARGS__; cout << endl; } while (false)
#define WRITELN(...)  do { (_Writer{cout, "\n"}), __VA_ARGS__; cout << endl; } while (false)
#define WRITE2D(vevector) FORE(row : vevector) WRITE(row)
#ifdef _DEBUG
#define DEBUG(...) (_Writer{cerr}), "DEBUG -> ", __VA_ARGS__, "\n"
#else
#define DEBUG(...)
#endif

// -- vevector -- //
template <class T> struct vevector : vector<vector<T>> { vevector(size_t n = 0, size_t m = 0, const T& initial = T()) : vector<vector<T>>(n, vector<T>(m, initial)) { } };
template <class T> struct vevevector : vector<vevector<T>> { vevevector(size_t n = 0, size_t m = 0, size_t l = 0, const T& initial = T()) : vector<vevector<T>>(n, vevector<T>(m, l, initial)) { } };
template <class T> struct vevevevector : vector<vevevector<T>> { vevevevector(size_t n = 0, size_t m = 0, size_t l = 0, size_t k = 0, const T& initial = T()) : vector<vevevector<T>>(n, vevevector<T>(m, l, k, initial)) { } };

namespace std {
	template <class T1, class T2> istream& operator >> (istream& in, pair<T1, T2>& p) { in >> p.first >> p.second; return in; }
	template <class T1, class T2> ostream& operator << (ostream& out, const pair<T1, T2>& p) { out << p.first << " " << p.second; return out; }
}

template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; REP(i, n) { v.push_back(read<T>()); } return v; }
template <class T> vevector<T> read(int n, int m) { vevector<T> v; REP(i, n) v.push_back(read<T>(m)); return v; }
template <class T> vector<T> readjag() { return read<T>(read<int>()); }
template <class T> vevector<T> readjag(int n) { vevector<T> v; REP(i, n) v.push_back(readjag<T>()); return v; }

template <class T> struct iter_range_t { T beg, end; };
template <class T> iter_range_t<T> iter_range(T beg, T end) { return iter_range_t<T>{beg, end}; }
template <class T> ostream& operator << (ostream& out, iter_range_t<T> v) { if (v.beg != v.end) { out << *v.beg++; while (v.beg != v.end) { out << " " << *v.beg++; } } return out; }
template <class T> ostream& operator << (ostream& out, const vector<T>& v) { return out << iter_range(allof(v)); }

// -- etc -- //
template <class T> T infinity_value();
template <> int infinity_value<int>() { return int(1) << 30; }
template <> llong infinity_value<llong>() { return llong(1) << 60; }
template <> double infinity_value<double>() { return 1e+300 * 1e+300; }
#define INF(T) infinity_value<T>()

inline int sign_of(double x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
template <class TInt> bool in_range(TInt val, TInt min, TInt max) { return val >= min && val < max; }
template <> bool in_range<double>(double val, double min, double max) { return val - min > -EPS && val - max < EPS; }
template <class TInt> bool in_range2d(TInt x, TInt y, TInt w, TInt h) { return x >= 0 && x < w && y >= 0 && y < h; }
vector<int> iotavn(int start, int count) { vector<int> r(count); iota(allof(r), start);	return r; }


//// start up ////
void solve();
int32_t main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(std::numeric_limits<double>::max_digits10);
	solve();

	return 0;
}


////////////////////
//// template end
////////////////////

void solve()
{
	READ(int, N);
	auto H = read<int>(N);

	int ans = 0;
	REP(i, N)
	{
		bool a = true;
		REP(j, i)
		{
			a &= H[j] <= H[i];
		}
		ans += a;
	}
	WRITE(ans);
}
