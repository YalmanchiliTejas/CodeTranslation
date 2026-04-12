// May this submission get accepted
#include <bits/stdc++.h>

// エイリアス
using  ll = long signed long;
using ull = long unsigned long;
using  ld = long double;
using namespace std;

// エイリアス (補完・コンパイルが重くなる)
// #include <boost/multiprecision/cpp_int.hpp>
// using mll = boost::multiprecision::cpp_int;

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define STEP(i, is, ie, step) for (long long i=(is), i##_end=(ie), i##_step = (step); i<=i##_end; i+=i##_step)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
#define FOREACH(i,q) for (auto &i : q)
template<class T> bool chmax(T &a, const T b) { if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T b) { if (a > b) {a = b; return true;} return false; }
constexpr int INF = numeric_limits<int>::max();
constexpr long long LINF = numeric_limits<long long>::max();
constexpr long double EPS = 1e-10L;
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define DUMP(q) DUMP_FUNC(q, #q, __FILE__, __LINE__)
template <typename T> void DUMP_PROC(T x) { cerr << x; }
void DUMP_PROC(string x) { cerr << '"' << x << '"'; }
template <typename T> void DUMP_PROC(vector<T> x) { cerr << "["; for (auto &xi : x) { DUMP_PROC(xi); cerr << (&xi != &*x.rbegin()?", ":""); } cerr << "]"; }
template <typename T> void DUMP_FUNC(T x, const char* name, const char* fn, int ln) { cerr << "\e[32m[DEBUG]\e[0m " << name << ": "; DUMP_PROC(x); cerr << " @ " << fn << "(" << ln << ")" << endl; }
template<class T> T gcd(T a, T b) { if (a < b) swap(a, b); while (b) swap(a %= b, b); return a; }
template<class T> T lcm(const T a, const T b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// 標準入出力
struct inp {
    size_t sz;
    inp(size_t _sz = 1) : sz(_sz) {}
    template <typename T> operator T () const { T a; cin >> a; return a; }
    template <typename T> operator vector<T> () const { vector<T> a(sz); for (size_t i = 0; i < sz; i++) cin >> a[i]; return a; }
    template <typename T, typename U> operator pair<T, U> () const { T f; U s; cin >> f >> s; return pair<T, U>(f, s); }
};
inp inp1; // input one
template <typename T> void say(const T x, const char* end = "\n") { cout << x << end; }
void say(const ld x, const char* end = "\n") { cout << setprecision(30) << x << end; }
template <typename T> void say(const vector<T> x, const char* sep = " ", const char* end = "\n") { REP(i, x.size()) { cout << x[i] << (i+1 == i_len ? end : sep); } }
template <typename T> void say(const vector<vector<T>> x, const char* sep = " ", const char* end = "\n") { REP(i, x.size()) { say(x[i], sep, end); } }

// モジュール


// 処理内容
int main() {
    
    ios::sync_with_stdio(false); // stdioを使うときはコメントアウトすること
    cin.tie(nullptr);            // インタラクティブ問題ではコメントアウトすること
    
    string s = inp1;
    say(Yes(s!="AAA"&&s!="BBB"));
    
}