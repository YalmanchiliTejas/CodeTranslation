#include <iostream>
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

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define VEC2(T, N, M) vector<N, vector<T>(M)>
#define inf 0x3f3f3f3f3f3f3f3f
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define VS vector<string>
#define VI vector<ll>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define pcc pair<char,char>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define eps 1e-14
#define FST first
#define SEC second
#define SETUP cin.tie(0), ios::sync_with_stdio(false), cout << setprecision(15) << std::fixed;

template <class T>
using vec2 = std::vector<vector<T>>;

namespace {
	struct input_returnner {
		ll N; input_returnner(ll N_ = 0) :N(N_) {}
		template<typename T> operator vector<T>() const { vector<T> res(N); for (auto &a : res) cin >> a; return std::move(res); }
		template<typename T> operator T() const { T res; cin >> res; return res; }
		template<typename T> T operator - (T right) { return T(input_returnner()) - right; }
		template<typename T> T operator + (T right) { return T(input_returnner()) + right; }
		template<typename T> T operator * (T right) { return T(input_returnner()) * right; }
		template<typename T> T operator / (T right) { return T(input_returnner()) / right; }
		template<typename T> T operator << (T right) { return T(input_returnner()) << right; }
		template<typename T> T operator >> (T right) { return T(input_returnner()) >> right; }
	};
	template<typename T> input_returnner in() { return in<T>(); }
	input_returnner in() { return input_returnner(); }
	input_returnner in(ll N) { return std::move(input_returnner(N)); }
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec) {
	for (T& x : vec) is >> x;
	return is;
}


template < typename T >
struct is_vector : std::false_type {};

template < typename T >
struct is_vector<std::vector<T>> : std::true_type {};

template < typename T >
constexpr bool is_vector_v = is_vector<T>::value;

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
	if (!v.empty()) {
		for (int i = 0; i < v.size(); ++i) {
			out << v[i] << (i == v.size() - 1 ? "\n" : (is_vector_v<T> ? "" : ", "));
		}
	}
	return out;
}

namespace std {
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
	template <typename ... TT>
	struct hash<std::tuple<TT...>>
	{
		size_t operator()(std::tuple<TT...> const& tt) const
		{
			size_t seed = 0;
			HashValueImpl<std::tuple<TT...> >::apply(seed, tt);
			return seed;
		}

	};
}

// ref: https://stackoverflow.com/questions/6245735/pretty-print-stdtuple
namespace aux {
	template<std::size_t...> struct seq {};

	template<std::size_t N, std::size_t... Is>
	struct gen_seq : gen_seq<N - 1, N - 1, Is...> {};

	template<std::size_t... Is>
	struct gen_seq<0, Is...> : seq<Is...> {};

	template<class Ch, class Tr, class Tuple, std::size_t... Is>
	void print_tuple(std::basic_ostream<Ch, Tr>& os, Tuple const& t, seq<Is...>) {
		using swallow = int[];
		(void)swallow {
			0, (void(os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), 0)...
		};
	}
} // aux::

template<class Ch, class Tr, class... Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...> const& t)
-> std::basic_ostream<Ch, Tr>&
{
	os << "(";
	aux::print_tuple(os, t, aux::gen_seq<sizeof...(Args)>());
	return os << ")";
}

template<class S, class T>
std::ostream & operator<<(std::ostream & os, const std::pair<S, T> & p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

// ref: https://stackoverflow.com/questions/8542591/c11-reverse-range-based-for-loo：p
template <typename T>
struct reversion_wrapper { T& iterable; };

template <typename T>
auto begin(reversion_wrapper<T> w) { return std::rbegin(w.iterable); }

template <typename T>
auto end(reversion_wrapper<T> w) { return std::rend(w.iterable); }

template <typename T>
reversion_wrapper<T> REV(T&& iterable) { return { iterable }; }


ll MOD = 1e9 + 7;

class prime;

void solve();

signed main() {
	SETUP;
	solve();
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}

#define int ll

// ---------------------- template ----------------------


void solve() {
	int N; cin >> N;
	vector<pii> xy;
	vector<int> v;
	int ma = 0;
	int mi = inf;
	REP(i, N) {
		int x, y; cin >> x >> y;
		if (x > y) swap(x, y);
		xy.emplace_back(x, y);
		ma = max(x, ma);
		ma = max(y, ma);
		mi = min(x, mi);
		mi = min(y, mi);
		v.push_back(x);
		v.push_back(y);
	}
	int lmax = 0;
	int lmin = inf;
	int res;
	{
		int rmax = 0;
		int rmin = inf;
		REP(i, N) {
			lmax = max(lmax, xy[i].first);
			lmin = min(lmin, xy[i].first);
			rmax = max(rmax, xy[i].second);
			rmin = min(rmin, xy[i].second);
		}
		res = (lmax - lmin) *(rmax - rmin);
	}
	{
		priority_queue<pii, vector<pii>, greater<pii> > que;
		multiset<int> se;
		vector<bool> ng(N);
		REP(i, N) {
			int x, y;
			tie(x, y) = xy[i];
			if (x == mi) {
				se.insert(y);
				ng[i] = true;
			}
			if (y == ma) {
				se.insert(x);
				if (ng[i]) {
					cout << res << endl;
					return;
				}
				ng[i] = true;
			}
			if (x != mi and y != ma) {
				se.insert(xy[i].first);
			}
		}
		REP(i,N) if(not ng[i]) que.emplace(xy[i].first, xy[i].second);
		int r  = inf;
		while (not que.empty()) {
			auto top = que.top(); que.pop();
			auto it = se.find(top.first);
			se.erase(it);
			se.insert(top.second);
			int a = *prev(se.end()) - *se.begin();
			r = min(r, a);
		}
		res = min(res, (ma - mi)*(r));
	}
	cout << res << endl;
}
