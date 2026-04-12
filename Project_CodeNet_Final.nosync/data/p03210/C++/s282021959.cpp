#include <vector> 
#include <list> 
#include <map>
#include <set>//2分探索木
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>// キュー　優先度付きキュー
#include <stack>
#include <complex>
#include <memory>
#include <assert.h>
#ifdef LOCAL
#include "UnionFind.h"//同じグループに属するか
#include "Prime.h"//素数判定
#include "RMQ.h"//区間最小値
#include "BIT.h"//累積和
#include "Dijkstra.h"//単一始点最短経路(負の辺があるときは動作しない)　O(ElogV)
#include "Kruskal.h"//最小全域木 O(ElogV)
#include "Factorial.h"//階乗　組み合わせ　 
#endif

using namespace std;

//conversion
//------------------------------------------
inline long long toInt(string s) { long long v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//chmin max
void chmin(int& a, int b) { a = min(a, b); }
void chmax(int& a, int b) { a = max(a, b);}
void chmin(long long& a, long long b) { a = min(a, b); }
void chmax(long long& a, long long b) { a = max(a, b); }
//math
//-------------------------------------------
template<class T> inline T sqr(T x) { return x * x; }

//typedef
//------------------------------------------
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<pii> vpii;

//container util
//------------------------------------------
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define each(t,c) for(typeof((c).begin()) t=(c).begin(); t!=(c).end(); ++t)
#define exist(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())


//文字列分割
std::vector<std::string> split(std::string str, set<char> del) {
	std::vector<std::string> result; std::string subStr;
	for (const char c : str) {
		if (exist(del, c)) { result.push_back(subStr); subStr.clear(); }
		else { subStr += c; }
	}
	result.push_back(subStr);
	return result;
}


//repetition
//------------------------------------------
#define FOR(t,a,b) for(int t=(a);t<(b);++t)
#define rep(t,n)  FOR(t,0,n)

//constant
//------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

//clear memory
//------------------------------------------
#define clr(a) memset((a), 0 ,sizeof(a))

//debug
//------------------------------------------
#if defined(__GNUC__) 
#include <assert.h>
#define ASSERT_(x) assert(x)
#else
#include <assert.h>
#define ASSERT_(x) assert(x)
#endif
#ifdef _DEBUG
#define dump(x)  cerr << #x << '=' << (x) << endl;
#define debug(x) cerr << #x << '=' << (x) << '('<<'L' << __LINE__ << ')' << ' ' << __FILE__ << endl;
#define ASSERT(x) {if (!(x)){std::cerr << "\nError!!\n" << "info string file:" << __FILE__ << " line:" << __LINE__ <<" "<< #x<< std::endl;ASSERT_(x);}}
#else
#define ASSERT(x) ((void)0)
#define debug(x) ((void)0)
#define dump(x)  ((void)0)
#endif // _DEBUG

//vector
template<class T> void showVector(vector<T>& v) {
	for (int i = 0; i < v.size(); ++i)
		cerr << v[i] << " ";
	cerr << endl;
}

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a) {
	return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
	return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//mod
//-------------------------------------------
const ll mod = 1000000007;
ll mod_pow(ll x, ll n, ll mod) {
	if (n == 0) { return 1; }
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) { res = res * x % mod; }
	return res;
}

//組み合わせ数
ll conbination(ll n, ll r) {
	if (r > n || r < 0LL) { return 0LL; }
	ll i;
	ll s = 1LL;
	for (i = 1LL; i <= r; i++) { s = s * (n + 1LL - i) / i; }
	return s;
}


//bitop
//-------------------------------------------
#if defined(__GNUC__)
#include <immintrin.h>
int popcount(int a) {
	return __builtin_popcount(a);
}
#elif defined(_MSC_VER)
#include <intrin.h>
int popcount(int a) {
	return __popcnt(a);
}
#endif 

//gcd lcm
//-------------------------------------------
ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


//YES_NO
//------------------------------------------
#define Yes_ cout<<"Yes"<<endl; return 0;
#define No_ cout<<"No"<<endl; return 0;

#define YES_ cout<<"YES"<<endl; return 0;
#define NO_ cout<<"NO"<<endl; return 0;

#define POSSIBLE cout<<"POSSIBLE"<<endl; return 0;
#define IMPOSSIBLE cout<<"IMPOSSIBLE"<<endl; return 0;

#define CC(x) cout << (x) << endl;
//matrix
//------------------------------------------
template <class T> class matrix : public vector< vector<T> > {
private:
	int tate_, yoko_;
public:
	matrix(const int tate__, const int yoko__) {
		ASSERT(tate__ > 0); ASSERT(yoko__ > 0);
		this->resize(tate__); for (size_t i = 0; i < this->size(); i++) { (*this)[i].resize(yoko__); }tate_ = tate__; yoko_ = yoko__;
	}
	matrix() {};
	int tate() const { return tate_; } int yoko() const { return yoko_; }
	void resizematrix(const int tate__, const int yoko__) {
		ASSERT(tate__ > 0); ASSERT(yoko__ > 0);
		this->resize(tate__); for (size_t i = 0; i < this->size(); i++) { (*this)[i].resize(yoko__); }tate_ = tate__; yoko_ = yoko__;
	}
	void setzero() { for (int i = 0; i < tate(); i++) for (int j = 0; j < yoko(); j++) { (*this)[i][j] = 0; } }
};

template<class T> std::ostream& operator<<(std::ostream & os, const matrix<T> & m)
{
	for (int j = 0; j < m.tate(); j++) { for (int i = 0; i < m.yoko(); i++) { os << (int)m[j][i]; }os << endl; }
	return os;
}
#if 1
//time
//------------------------------------------
#if defined(__GNUC__) 
#include <sys/time.h>
#include <immintrin.h>
#include <string.h>
ll starttime;
inline ll now() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	ll t = tv.tv_sec * 1000LL + tv.tv_usec / 1000LL;
	return t;
}
inline ll elapsed() { return now() - starttime; }
#else
#include <chrono>
#include <intrin.h>
typedef std::chrono::milliseconds::rep TimePoint;
inline TimePoint now() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count(); }
TimePoint starttime;
inline TimePoint elapsed() { return now() - starttime; }
#endif
#endif

//=====================================================

#ifndef LOCAL


#endif



int main() {
	

	int x;
	cin >> x;
	if (x == 3 || x == 5 || x == 7) {
		YES_;
	}
	NO_;
}

