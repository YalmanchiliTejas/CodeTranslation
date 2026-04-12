////////////////////////////////////////
///  tu3 pro-con template            ///
////////////////////////////////////////
#include "bits/stdc++.h"
using namespace std;

// -- loop macros -- //
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i,s,n) for (int i = (int)(s); i < (n); i++)
#define RFOR(i,s,n) for (int i = (n)-1; i >= (s); i--)
#define FOREACH(i,container) for (auto &&i : container)
#define allof(c) c.begin(), c.end()
#define partof(c,i,n) c.begin() + (i), c.begin() + (i) + (n)

// -- functors -- //
#define PREDICATE(t,a,exp) [&](const t & a) -> bool { return exp; }
#define COMPARISON(t,a,b,exp) [&](const t & a, const t & b) -> bool { return exp; }

#define PRED(a,exp) [&](const auto & a) -> bool { return exp; }
#define COMP(a,b,exp) [&](const auto & a, const auto & b) -> bool { return exp; }
#define CONV1(a,exp) [&](const auto & a) -> auto { return exp; }
#define CONV2(a,b,exp) [&](const auto & a, const auto & b) -> auto { return exp; }
#define CONV3(a,b,c,exp) [&](const auto & a, const auto & b, const auto & c) -> auto { return exp; }

// -- typedefs -- //
#define EPS 1e-9

typedef unsigned int uint;
typedef long long llong;
typedef unsigned long long ullong;

// -- I/O Helper -- //
struct _Reader { istream& cin; template <class T> _Reader operator ,(T& rhs) { cin >> rhs; return *this; } };
struct _Writer { ostream& cout; bool f{ false }; template <class T> _Writer operator ,(const T& rhs) { cout << (f ? " " : "") << rhs; f = true; return *this; } };
#define READ(t,...) t __VA_ARGS__; (_Reader{cin}), __VA_ARGS__
#define WRITE(...) (_Writer{cout}), __VA_ARGS__, "\n"
#define DEBUG(...) (_Writer{cerr}), __VA_ARGS__, "\n"

// -- vevector -- //
template <class T> struct vevector : public vector<vector<T>> { vevector(size_t n = 0, size_t m = 0, const T & initial = T()) : vector<vector<T>>(n, vector<T>(m, initial)) { } };
template <class T> struct vevevector : public vector<vevector<T>> { vevevector(size_t n = 0, size_t m = 0, size_t l = 0, const T & initial = T()) : vector<vevector<T>>(n, vevector<T>(m, l, initial)) { } };
template <class T> struct vevevevector : public vector<vevevector<T>> { vevevevector(size_t n = 0, size_t m = 0, size_t l = 0, size_t k = 0, const T & initial = T()) : vector<vevevector<T>>(n, vevevector<T>(m, l, k, initial)) { } };

namespace std {
	template <class T1, class T2> inline istream& operator >> (istream& in, pair<T1, T2>& p) { in >> p.first >> p.second; return in; }
	template <class T1, class T2> inline ostream& operator << (ostream& out, const pair<T1, T2>& p) { out << p.first << " " << p.second; return out; }
}

template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; REP(i, n) { v.push_back(read<T>()); } return v; }
template <class T> vevector<T> read(int n, int m) { vevector<T> v; REP(i, n) v.push_back(read<T>(m)); return v; }
template <class T> vector<T> readjag() { return read<T>(read<int>()); }
template <class T> vevector<T> readjag(int n) { vevector<T> v; REP(i, n) v.push_back(readjag<T>()); return v; }

template <class T> struct iter_pair_t { T beg, end; };
template <class T> iter_pair_t<T> iter_pair(T beg, T end) { return iter_pair_t<T>{beg, end}; }
template <class T> ostream& operator << (ostream& out, iter_pair_t<T> v) { if (v.beg != v.end) { out << *v.beg++; while (v.beg != v.end) { out << " " << *v.beg++; } } return out; }
template <class T> ostream& operator << (ostream& out, const vector<T>& v) { return out << iter_pair(begin(v), end(v)); }

// -- etc -- //
template <class T> T infinity_value();
#define DEFINE_INFINITY_VALUE(T, val) template <> constexpr T infinity_value<T>() { return (val); }
DEFINE_INFINITY_VALUE(int, 1 << 28);
DEFINE_INFINITY_VALUE(uint, 1u << 28);
DEFINE_INFINITY_VALUE(llong, 1ll << 60);
DEFINE_INFINITY_VALUE(ullong, 1ull << 60);
DEFINE_INFINITY_VALUE(double, HUGE_VAL);
DEFINE_INFINITY_VALUE(float, HUGE_VAL);
#define INF(T) infinity_value<T>()

inline int sign_of(double x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
template <class TInt> bool in_range(TInt val, TInt min, TInt max) { return val >= min && val < max; }
template <> bool in_range<double>(double val, double min, double max) { return val - min > -EPS && val - max < EPS; }
template <> bool in_range<float>(float val, float min, float max) { return val - min > -EPS && val - max < EPS; }
template <class TInt> bool in_range2d(TInt x, TInt y, TInt w, TInt h) { return x >= 0 && x < w && y >= 0 && y < h; }
vector<int> iotavn(int start, int count) { vector<int> r(count); iota(allof(r), start);	return r; }


//// start up ////
void solve();
int main()
{
	//// for local debugging
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//auto classic_table = ctype<char>::classic_table();
	//vector<ctype<char>::mask> ctable(classic_table, classic_table + ctype<char>::table_size);
	//ctable[':'] |= ctype_base::space; // as delimitor
	//ctable[','] |= ctype_base::space; // as delimitor
	//cin.imbue(locale(cin.getloc(), new ctype<char>(ctable.data())));

	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(std::numeric_limits<double>::max_digits10);
	solve();

	return 0;
}

////////////////////
/// template end ///
////////////////////

void solve()
{
	READ(int, X);
	WRITE(X == 3 || X == 5 || X == 7 ? "YES" : "NO");
}