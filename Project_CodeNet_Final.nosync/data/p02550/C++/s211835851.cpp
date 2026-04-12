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

/*
Doubling(sz, lim_t, f): 配列サイズsz, 反復回数上限lim_t, 関数fで初期化する
set_next(k, x): 値kに1回操作を行うとxへ変化するよう設定する
build(): ダブリングを構築する
query(k, t): 値kにt回操作を行ったとき、f(k)の総和を返却する
*/
template<typename T, typename Function>
class DoublingSum {
public:
	const ll LOG;
	vector< vector< ll > > table;
	vector< vector< T > > sum;
	Function f;

	DoublingSum(ll sz, ll lim_t, Function f) : LOG(64 - __builtin_clzll(lim_t)), f(f) {
		table.assign(LOG, vector< ll >(sz, -1));
		sum.assign(LOG, vector< T >(sz, 0));
	}

	void set_next(ll k, ll x) {
		table[0][k] = x;
	}

	void build() {
		for(ll i = 0, size = sum[0].size(); i < size; i++) {
			sum[0][i] = f(i);
		}
		for(ll k = 0; k + 1 < LOG; k++) {
			for(ll i = 0, size = table[k].size(); i < size; i++) {
				if(table[k][i] == -1) {
					table[k + 1][i] = -1;
				} else {
					table[k + 1][i] = table[k][table[k][i]];
					sum[k + 1][i] = sum[k][i] + sum[k][table[k][i]];
				}
			}
		}
	}

	T query(ll k, ll t) { 
		T ans = 0;
		for(ll i = LOG - 1; i >= 0; i--) {
			if((t >> i) & 1) {
				ans += sum[i][k];
				k = table[i][k];
			}
		}
		return ans;
	}
};

/*-----8<-----library-----8<-----*/

void solve() {
	ll N, X, M;
	cin >> N >> X >> M;

	auto F = [](ll x){ return x; };
	DoublingSum<ll,decltype(F)> doubling(M, 1e10+1, F);

	auto g = [&](ll x){ return (x*x)%M; };
	rep(i,M){
		//操作1回で i -> g(i) へ移動
		doubling.set_next(i, g(i));
	}
	doubling.build();
	debug(doubling.table);
	debug(doubling.sum);

	// k=X からスタートして N 回操作後の F(k) の総和
	ll ans = doubling.query(X, N);
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
