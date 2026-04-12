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

inline constexpr ll extgcd(ll a, ll b, ll &x, ll &y){ ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
inline constexpr ll invmod(ll a, ll m = MOD){ ll x = 0, y = 0; extgcd(a, m, x, y); return (x + m) % m; }
class Modint{
public:
	ll _num;
	constexpr Modint() : _num() { _num = 0; }
	constexpr Modint(ll x) : _num() { _num = x % MOD; if(_num < 0) _num += MOD; }
	inline constexpr Modint operator= (int x){ _num = x % MOD; if(_num<0) _num += MOD; return *this; }
	inline constexpr Modint operator= (ll x){ _num = x % MOD; if(_num<0) _num += MOD; return *this; }
	inline constexpr Modint operator= (Modint x){ _num = x._num; return *this; }
	inline constexpr Modint operator+ (int x){ return Modint(_num + x); }
	inline constexpr Modint operator+ (ll x){ return Modint(_num + x); }
	inline constexpr Modint operator+ (Modint x){ ll a = _num + x._num; if(a >= MOD) a -= MOD; return Modint{a}; }
	inline constexpr Modint operator+=(int x){ _num += x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator+=(ll x){ _num += x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator+=(Modint x){ _num += x._num; if(_num >= MOD) _num -= MOD; return *this; }
	inline constexpr Modint operator++(){ _num++; if(_num == MOD) _num = 0; return *this; }
	inline constexpr Modint operator- (int x){ return Modint(_num - x); }
	inline constexpr Modint operator- (ll x){ return Modint(_num - x); }
	inline constexpr Modint operator- (Modint x){ ll a = _num - x._num; if(a < 0) a += MOD; return Modint{a}; }
	inline constexpr Modint operator-=(int x){ _num -= x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator-=(ll x){ _num -= x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator-=(Modint x){ _num -= x._num; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator--(){ _num--; if(_num == -1) _num = MOD - 1; return *this; }
	inline constexpr Modint operator* (int x){ return Modint(_num * (x % MOD)); }
	inline constexpr Modint operator* (ll x){ return Modint(_num * (x % MOD)); }
	inline constexpr Modint operator* (Modint x){ return Modint{_num * x._num % MOD}; }
	inline constexpr Modint operator*=(int x){ _num *= Modint(x); _num %= MOD; return *this; }
	inline constexpr Modint operator*=(ll x){ _num *= Modint(x); _num %= MOD; return *this; }
	inline constexpr Modint operator*=(Modint x){ _num *= x._num; _num %= MOD; return *this; }
	inline constexpr Modint operator/ (int x){ return Modint(_num * invmod(Modint(x), MOD)); }
	inline constexpr Modint operator/ (ll x){ return Modint(_num * invmod(Modint(x), MOD)); }
	inline constexpr Modint operator/ (Modint x){ return Modint{_num * invmod(x._num, MOD) % MOD}; }
	inline constexpr Modint operator/=(int x){ _num *= invmod(Modint(x), MOD); _num %= MOD; return *this; }
	inline constexpr Modint operator/=(ll x){ _num *= invmod(Modint(x), MOD); _num %= MOD; return *this; }
	inline constexpr Modint operator/=(Modint x){ _num *= invmod(x._num, MOD); _num %= MOD; return *this; }
	inline constexpr Modint pow(ll n){ ll i = 1, x = n>=0 ? n : -n; Modint ans = 1, cnt = n>=0 ? *this : Modint(1) / *this; while(i <= x){ if(x & i){ ans *= cnt; x ^= i; } cnt *= cnt; i *= 2; } return ans; }
	inline constexpr operator ll() const { return _num; }
};
inline std::istream& operator>>(std::istream &s, Modint &x){ ll t; s>>t; x=t; return s; }
vector<Modint> fac(1, 1), inv(1, 1);
inline void reserve(size_t a){
	if(fac.size() >= a) return;
	if(a < fac.size() * 2) a = fac.size() * 2;
	if(a >= MOD) a = MOD;
	while(fac.size() < a) fac.push_back(fac.back() * ll(fac.size()));
	inv.resize(fac.size());
	inv.back() = Modint(1) / fac.back();
	for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
inline Modint factorial(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
inline Modint nPk_loop(ll n, ll k){ if(n<k) return 0; Modint val(1); for(ll i=n;i>(n-k);i--)val*=i; return val; }
inline Modint nCk_loop(ll n, ll k){ if(n<k) return 0; Modint val(1); k=min(k,n-k); for(ll i=n;i>(n-k);i--)val*=i; for(ll i=k;i>1;i--)val/=i; return val; };
inline Modint nPk(ll n, ll k){ if(k < 0 || n < k) return 0; if(n>=(ll)1e7) return nPk_loop(n, k); reserve(n + 1); return fac[n] * inv[n - k]; }
inline Modint nCk(ll n, ll k){ if(k < 0 || n < k) return 0; if(n>=(ll)1e7) return nCk_loop(n, k); reserve(n + 1); return fac[n] * inv[k] * inv[n - k]; }
inline Modint nHk(ll n, ll k){ return nCk(n + k - 1, k); } //n種類のものから重複を許してk個選ぶ=玉k個と仕切りn-1個

class Edge {
public:
	ll from,to,cost;
	Edge() {}
	Edge(ll from, ll to, ll cost) : from(from), to(to), cost(cost) {}
};
ostream& operator<<(ostream& s, const Edge& e) {
	s << "{ " << e.from << " -> " << e.to << ", " << e.cost << " }";
	return s;
}

/*
計算量：O(ElogV)
引数
　g:探索するグラフ
　start:探索するスタートノード番号
戻り値
　dist:スタートノードから各頂点までの距離
　prev:最短路木の親頂点
*/
void dijkstra(const vector<vector<Edge>> &g, ll start, vector<ll> &dist, vector<ll> &prev, vector<Modint> &v) {
	ll gsize = g.size();
	dist.assign(gsize, INF); dist[start] = 0;
	prev.assign(gsize, -1);
	v.assign(gsize, 0);
	v[start]=1;
	
	priority_queue<Edge, vector<Edge>, function<bool(Edge,Edge)>> que(
		[](const Edge &x, const Edge &y){
			return x.cost != y.cost ? (x.cost > y.cost) : 
				(x.from != y.from ? x.from < y.from : x.to < y.to);
		}
	);
	que.push(Edge(-1, start, 0));
	while (!que.empty()) {
		Edge e = que.top();
		que.pop();
		//if (prev[e.to] != -1) continue;
		prev[e.to] = e.from;
		for(Edge f : g[e.to]) {
			if (dist[f.to] > e.cost + f.cost) {
				dist[f.to] = e.cost + f.cost;
				v[f.to]=v[f.from];
				que.push(Edge(f.from, f.to, e.cost+f.cost));
			}else if(dist[f.to] == e.cost + f.cost){
				v[f.to]+=v[f.from];
			}
		}
	}
}
//最短路木の親頂点を元にstart->goalの経路を作成
vector<ll> buildPath(const vector<ll> &prev, ll goal) {
	vector<ll> path;
	for (ll u = goal; u >= 0; u = prev[u])
		path.push_back(u);
	reverse(path.begin(), path.end());
	return path;
}

/*-----8<-----library-----8<-----*/

void solve() {
	ll N,M;
	cin>>N>>M;
	ll S,T;
	cin>>S>>T;
	S--;T--;
	vector<ll> U(M),V(M),C(M);
	vector<vector<Edge>> g(N);
	rep(i,M){
		ll a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		g[a].emplace_back(a,b,c);
		g[b].emplace_back(b,a,c);
		U[i]=a;
		V[i]=b;
		C[i]=c;
	}

	vector<ll> distS, prevS;
	vector<Modint> vS;
	dijkstra(g, S, distS, prevS, vS);
	vector<ll> distT, prevT;
	vector<Modint> vT;
	dijkstra(g, T, distT, prevT, vT);
	debug(distS);
	debug(distT);
	debug(vS);
	debug(vT);
	ll mindist=distS[T];

	Modint ans=vS[T]*vS[T];//２人が途中で出会う場合も含めた、２人の最短経路の選び方

	ll t=0;//２人が点で出会う選び方
	rep(i,N){
		if(distS[i]==distT[i] && mindist==2*distS[i]){
			t+=vS[i]*vS[i]*vT[i]*vT[i];
		}
	}

	ll s=0;//２人が辺で出会う選び方
	rep(i,M){
		//u-v最短経路として使われる && S-u*2<最短経路長 && T-v*2<最短経路長
		ll u=U[i];
		ll v=V[i];
		if(distS[u]>distS[v])swap(u,v);
		if(distS[u]+distT[v]+C[i]==mindist && distS[u]*2<mindist && distT[v]*2<mindist){
			s+=vS[u]*vS[u]*vT[v]*vT[v];
		}
	}
	debug(ans,t,s);
	ans-=(t+s);
	p(ans);
}

signed main() {
	solve();
	return 0;
}

