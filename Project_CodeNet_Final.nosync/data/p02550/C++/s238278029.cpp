#include <bits/stdc++.h>
using namespace std;
/*
#include <atcoder/all>
using namespace atcoder;
*/
/*
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using bll = boost::multiprecision::cpp_int;
using bdouble = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<100>>;
using namespace boost::multiprecision;
*/
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE 1
	#include <boost/stacktrace.hpp>
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
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void catch_SIGSEGV([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#endif
#ifdef LOCAL_DEV
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	template <typename T, size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T>>& vv) {
		s << "\\\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << ":" << __LINE__ << " (" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
#else
	#define debug(...) do {} while (false)
#endif
//#define int long long
using ll = long long;
//constexpr int INF = (ll)1e9 + 7; //INT_MAX = (1<<31)-1 = 2147483647
constexpr ll INF = (ll)1e18; //(1LL<<63)-1 = 9223372036854775807
constexpr ll MOD = (ll)1e9 + 7; //primitive root = 5
//constexpr ll MOD = 998244353; //primitive root = 3
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

//区間add, 区間sum ができる
template< typename T >
class BinaryIndexedTree {
public:
	class BinaryIndexedTreeNaive {
	public:
		ll size;
		vector<T> data;
		BinaryIndexedTreeNaive(ll N) : size(N+1), data(size, 0) {}

		// sum [0, i)
		T sum(ll i) {
			T ret = 0;
			for(--i; i>=0; i=(i&(i+1))-1) ret += data[i];
			return ret;
		}

		// sum [i, j)
		T sum(ll i, ll j) {
			return sum(j) - sum(i);
		}

		// add x to i
		void add(ll i, T x) {
			for(; i < size; i|=i+1) data[i] += x;
		}
	};
	ll size;
	BinaryIndexedTreeNaive b,c;
	BinaryIndexedTree(ll N) : size(N), b(size), c(size) {}

	// add x to [i, j) 
	void add(ll i, ll j, T x) {
		if (i>=j) return;
		b.add(i,x*-i);
		b.add(j,x*j);
		c.add(i,x);
		c.add(j,x*-1);
	}

	// sum [0, i)
	T sum(ll i) { 
		return b.sum(i+1) + c.sum(i+1)*i;
	}

	// sum [i, j)
	T sum(ll i, ll j) {
		if (i>=j) return 0;
		return sum(j) - sum(i);
	}
};
template<typename T> std::ostream& operator<<(std::ostream& s, BinaryIndexedTree<T>& bit) { 
	for(ll i=0; i<bit.size; i++) s << bit.sum(i, i+1) << "\t\n"[i==bit.size-1];
	return s;
}

/*-----8<-----library-----8<-----*/

constexpr ll N_MAX = 1e10;
constexpr ll M_MAX = 1e5;

ll N, X, M;

void solve() {
	cin >> N >> X >> M;

	ll ans = -1;
	vector<ll> deta(M,-1);
	BinaryIndexedTree<ll> bit(M);

	auto f=[&](ll x){
		x%=M;
		return (x*x)%M;
	};
	ll x=X;
	ll sum=0;
	ll c=0;
	rep(i,N){
		if(deta[x]!=-1){

			ll index=i-deta[x];
			ll kaisu=(N-i)/index;
			ll amari=(N-i)%index;
			ll b=bit.sum(deta[x],i);
			ans=sum+kaisu*b;
			rep(k,amari){
				ans+=x;
				x=f(x);				
			}

			break;
		}
		if(deta[x]==-1)c++;
		debug(i,c);
		deta[x]=i;
		sum+=x;
		bit.add(i,i+1,x);
		x=f(x);
	}
	if(ans==-1)ans=sum;
	cout << ans << '\n';
}

// https://atcoder.jp/contests/abc179/tasks/abc179_e
signed main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	//ll Q; cin >> Q; while(Q--)solve();
	solve();
	return 0;
}
