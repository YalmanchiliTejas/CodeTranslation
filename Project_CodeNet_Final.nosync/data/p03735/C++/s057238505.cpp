#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
	#include <boost/multiprecision/cpp_int.hpp>
	#include <boost/multiprecision/cpp_dec_float.hpp>
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::cpp_dec_float_100;
#endif
#ifdef LOCAL_DEV
	void debug_impl() { std::cerr << std::endl; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__);} while (false)
#else
	#define debug(...) do { } while (false)
#endif
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE
	#include <boost/stacktrace.hpp>
	namespace std {
		template<typename T> class dvector : public std::vector<T> {
		public:
			dvector() : std::vector<T>() {}
			explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
			dvector(const std::vector<T>& v) : std::vector<T>(v) {}
			dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
			dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
			dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
			T& operator[](size_t n) {
				try { return this->at(n); } catch (const std::exception& e) {
					std::cerr << boost::stacktrace::stacktrace() << std::endl; return this->at(n);
				}
			}
			const T& operator[](size_t n) const {
				try { return this->at(n); } catch (const std::exception& e) {
					std::cerr << boost::stacktrace::stacktrace() << std::endl; return this->at(n);
				}
			}
		};
	}
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		dbool(const dbool &b) : boolvalue(b.boolvalue) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector<T>& v) {
		for (int i = 0, len = v.size(); i < len; ++i){ s << v[i]; if (i < len - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const dvector< dvector<T> >& vv) {
		for (int i = 0, len = vv.size(); i < len; ++i){ s << vv[i] << std::endl; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{" << std::endl; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << std::endl; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) { 
		return s << "(" << p.first << ", " << p.second << ")"; }
	#define vector dvector
	#define bool dbool
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE(int e) { std::cerr << boost::stacktrace::stacktrace() << std::endl; throw SIGFPE_exception();	}
	void catch_SIGSEGV(int e) { std::cerr << boost::stacktrace::stacktrace() << std::endl; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#endif
//#define int long long
using ll = long long;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1LL, 0LL, -1LL, 0LL};
constexpr ll dy[4] = {0LL, 1LL, 0LL, -1LL};
constexpr ll dx8[8] = {1LL, 0LL, -1LL, 0LL, 1LL, 1LL, -1LL, -1LL};
constexpr ll dy8[8] = {0LL, 1LL, 0LL, -1LL, 1LL, -1LL, 1LL, -1LL};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T> &v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T> inline bool chmax(T &a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T &a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T> &v) { v.erase(unique(v.begin(), v.end()), v.end()); }

/*-----8<-----template-----8<-----*/
template< typename Monoid, typename F >
class SegmentTree {
public:
	ll sz;
	vector< Monoid > seg;
	const F f;
	const Monoid M1;

	SegmentTree(ll n, const F f, const Monoid &M1) : f(f), M1(M1) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}

	void set(ll k, const Monoid &x) {
		seg[k + sz] = x;
	}

	void build() {
		for(ll k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	void update(ll k, const Monoid &x) {
		k += sz;
		seg[k] = x;
		while(k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	Monoid query(ll a, ll b) {
		Monoid L = M1, R = M1;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) L = f(L, seg[a++]);
			if(b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	Monoid operator[](const ll &k) const {
		return seg[k + sz];
	}

	template< typename C >
	ll find_subtree(ll a, const C &check, Monoid &M, bool type) {
		while(a < sz) {
			Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
			if(check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}

	template< typename C >
	ll find_first(ll a, const C &check) {
		Monoid L = M1;
		if(a <= 0) {
			if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
			return -1;
		}
		ll b = sz;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) {
				Monoid nxt = f(L, seg[a]);
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
			if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
			return -1;
		}
		ll a = sz;
		for(b += sz; a < b; a >>= 1, b >>= 1) {
			if(b & 1) {
				Monoid nxt = f(seg[--b], R);
				if(check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};
template< typename Monoid, typename F >
std::ostream& operator<<(std::ostream& s, SegmentTree<Monoid,F>& seg) { 
	for(ll i=0; i<seg.sz; i++) s << seg[i] << "\t\n"[i==seg.sz-1];
	return s;
}

/*-----8<-----library-----8<-----*/

void solve() {
	ll N;
	cin>>N;
	vector<pair<ll,ll>> a(N);
	rep(i,N){
		cin>>a[i].first>>a[i].second;
		if(a[i].first>a[i].second)swap(a[i].first,a[i].second);
	}

	sort(all(a));
	ll rmin=INF,rmax=-INF,bmin=INF,bmax=-INF;
	rep(i,N){
		chmin(rmin,a[i].first);
		chmax(rmax,a[i].first);
		chmin(bmin,a[i].second);
		chmax(bmax,a[i].second);
	}
	ll ans=(rmax-rmin)*(bmax-bmin);

	auto minl = [](ll x,ll y){return min(x,y);}; //0LL
	auto maxl = [](ll x,ll y){return max(x,y);}; //0LL
	SegmentTree<ll,decltype(minl)> rminseg(N, minl, INF);
	SegmentTree<ll,decltype(maxl)> rmaxseg(N, maxl, -INF);
	SegmentTree<ll,decltype(minl)> bminseg(N, minl, INF);
	SegmentTree<ll,decltype(maxl)> bmaxseg(N, maxl, -INF);

	rep(i,N){
		rminseg.set(i,a[i].first);
		rmaxseg.set(i,a[i].first);
		bminseg.set(i,a[i].second);
		bmaxseg.set(i,a[i].second);
	}
	rminseg.build();
	rmaxseg.build();
	bminseg.build();
	bmaxseg.build();

	rep(i,N){
		ll rmin=min(rminseg.query(0,i), bminseg.query(i,N));
		ll bmin=min(bminseg.query(0,i), rminseg.query(i,N));
		ll rmax=max(rmaxseg.query(0,i), bmaxseg.query(i,N));
		ll bmax=max(bmaxseg.query(0,i), rmaxseg.query(i,N));
		ll t=(rmax-rmin)*(bmax-bmin);
		debug(rmax,rmin,bmax,bmin,t);
		chmin(ans,t);
	}
	p(ans);
}

signed main() {
	solve();
	return 0;
}

