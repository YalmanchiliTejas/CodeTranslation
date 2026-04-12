#include <bits/stdc++.h>
using namespace std;
#if __has_include(<boost/multiprecision/cpp_int.hpp>)
	#include <boost/multiprecision/cpp_int.hpp>
	#include <boost/multiprecision/cpp_dec_float.hpp>
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<100>>;
	using namespace boost::multiprecision;
#endif
#if __has_include(<boost/stacktrace.hpp>)
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE 1
	#include <boost/stacktrace.hpp>
#endif
#ifdef LOCAL_TEST
	namespace std {
		template<typename T> class dvector : public std::vector<T> {
		public:
			dvector() : std::vector<T>() {}
			explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
			dvector(const std::vector<T>& v) : std::vector<T>(v) {}
			dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
			dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::reverse_iterator first, const typename std::vector<T>::reverse_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_iterator first, const typename std::vector<T>::const_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_reverse_iterator first, const typename std::vector<T>::const_reverse_iterator last) : std::vector<T>(first, last) {}
			T& operator[](size_t n) {
				try { return this->at(n); } catch (const std::exception& e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n); }
			}
			const T& operator[](size_t n) const {
				try { return this->at(n); } catch (const std::exception& e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n); }
			}
		};
	}
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	#define vector dvector
	#define bool dbool
#endif
#ifdef LOCAL_DEV
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T>>& vv) {
		s << "\\\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T, size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void catch_SIGSEGV([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
#else
	#define debug(...) do {} while (false)
#endif
//#define int long long
using ll = long long;
//constexpr int INF = (ll)1e9 + 7;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T>& v) { v.erase(std::unique(v.begin(), v.end()), v.end()); }

/*-----8<-----template-----8<-----*/

namespace makevectordetail {
	template <typename Tp, size_t N>
	std::vector<Tp> make_vector(
		std::vector<size_t>& sizes,
		typename std::enable_if<(N == 1), Tp const&>::type x
	) {
		return std::vector<Tp>(sizes[0], x);
	}
	template <typename Tp, size_t N>
	auto make_vector(
		std::vector<size_t>& sizes,
		typename std::enable_if<(N > 1), Tp const&>::type x
	) {
		size_t size = sizes[N-1];
		sizes.pop_back();
		return std::vector<decltype(make_vector<Tp, N-1>(sizes, x))>(
			size, make_vector<Tp, N-1>(sizes, x)
		);
	}
}
template <typename Tp, typename sizetype, size_t N>
auto make_vector(sizetype const(&sizes)[N], Tp const& x = Tp()) {
	std::vector<size_t> s(N);
	for (size_t i = 0; i < N; ++i) s[i] = sizes[N-i-1];
	return makevectordetail::make_vector<Tp, N>(s, x);
}
//vector<vector<vector<ll>>> dp = make_vector<ll>({1, 2, 3}, 0LL);


template< typename Monoid, typename OperatorMonoid, typename F , typename G , typename H >
class LazySegmentTree {
public:
	ll sz, height;
	vector< Monoid > data;
	vector< OperatorMonoid > lazy;
	const F f;
	const G g;
	const H h;
	const Monoid M1;
	const OperatorMonoid OM0;

	LazySegmentTree(ll n, const F f, const G g, const H h, const Monoid &M1, const OperatorMonoid OM0)
			: f(f), g(g), h(h), M1(M1), OM0(OM0) {
		sz = 1;
		height = 0;
		while(sz < n) sz <<= 1, height++;
		data.assign(2 * sz, M1);
		lazy.assign(2 * sz, OM0);
	}

	void set(ll k, const Monoid &x) {
		data[k + sz] = x;
	}

	void build() {
		for(ll k = sz - 1; k > 0; k--) {
			data[k] = f(data[2 * k + 0], data[2 * k + 1]);
		}
	}

	inline void propagate(ll k) {
		if(lazy[k] != OM0) {
			lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
			lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
			data[k] = reflect(k);
			lazy[k] = OM0;
		}
	}

	inline Monoid reflect(ll k) {
		return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
	}

	inline void recalc(ll k) {
		while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
	}

	inline void thrust(ll k) {
		for(ll i = height; i > 0; i--) propagate(k >> i);
	}

	void update(ll a, ll b, const OperatorMonoid &x) {
		thrust(a += sz);
		thrust(b += sz - 1);
		for(ll l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) lazy[l] = h(lazy[l], x), ++l;
			if(r & 1) --r, lazy[r] = h(lazy[r], x);
		}
		recalc(a);
		recalc(b);
	}

	Monoid query(ll a, ll b) {
		thrust(a += sz);
		thrust(b += sz - 1);
		Monoid L = M1, R = M1;
		for(ll l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) L = f(L, reflect(l++));
			if(r & 1) R = f(reflect(--r), R);
		}
		return f(L, R);
	}

	Monoid operator[](const ll &k) {
		return query(k, k + 1);
	}

	template< typename C >
	ll find_subtree(ll a, const C &check, Monoid &M, bool type) {
		while(a < sz) {
			propagate(a);
			Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
			if(check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}

	template< typename C >
	ll find_first(ll a, const C &check) {
		Monoid L = M1;
		if(a <= 0) {
			if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
			return -1;
		}
		thrust(a + sz);
		ll b = sz;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) {
				Monoid nxt = f(L, reflect(a));
				if(check(nxt)) return find_subtree(a, check, L, false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}

	template< typename C >
	ll find_last(ll b, const C &check) {
		Monoid R = M1;
		if(b >= sz) {
			if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
			return -1;
		}
		thrust(b + sz - 1);
		ll a = sz;
		for(b += sz; a < b; a >>= 1, b >>= 1) {
			if(b & 1) {
				Monoid nxt = f(reflect(--b), R);
				if(check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};
template< typename Monoid, typename OperatorMonoid, typename F , typename G , typename H >
std::ostream& operator<<(std::ostream& s, LazySegmentTree<Monoid,OperatorMonoid,F,G,H>& seg) { 
	for(ll i=0; i<seg.sz; i++) s << seg[i] << "\t\n"[i==seg.sz-1];
	return s;
}
/*-----8<-----library-----8<-----*/

constexpr ll N_MAX = 2;
constexpr ll M_MAX = 2;
constexpr ll A_I_MAX = 1000000000;

void solve() {
	ll N, M;
  	scanf("%lld%lld", &N, &M);
	vector<vector<pair<ll,ll>>> a(N);
	rep(i, M) {
		ll l,r,c;
		scanf("%lld%lld%lld", &l, &r, &c);
		l--;
		r--;
		a[r].push_back({l,c});
	}

	auto F = [](ll x,ll y){return x+y;}; //0LL
	auto G = [](ll x,ll y){return max(x,y);}; //0LL
	LazySegmentTree<ll,ll,decltype(G),decltype(F),decltype(F)> seg(N, G, F, F, 0, 0);

	rep(r,N){
		ll t=seg.query(0,N);
		seg.update(r, r+1, t);
		for(auto [l,c]:a[r]){
			seg.update(l, r+1, c);
		}
	}

	ll ans=seg.query(0,N);
	printf("%lld\n", ans);
}

signed main() {
	solve();
	return 0;
}
