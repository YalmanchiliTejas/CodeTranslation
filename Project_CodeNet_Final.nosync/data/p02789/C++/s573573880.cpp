// May this submission get accepted
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define STEP(i, is, ie, step) for (long long i=(is), i##_end=(ie), i##_step = (step); i<=i##_end; i+=i##_step)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
template<class T> bool chmax(T &a, const T &b) { if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) {a = b; return true;} return false; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) do { cerr << "[DEBUG] " #q ": ["; REP(DUMPALL_ITR, (q).size()) { cerr << (q)[DUMPALL_ITR] << (DUMPALL_ITR == DUMPALL_ITR_len-1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; } while (false)
template<class T> T gcd(T a, T b) { if (a < b) std::swap(a, b); while (b) std::swap(a %= b, b); return a; }
template<class T> T lcm(const T a, const T b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
#define DANCE_ long
#define ROBOT_ unsigned
#define HUMAN_ signed
using  ll = DANCE_ HUMAN_ DANCE_;
using ull = DANCE_ ROBOT_ DANCE_;
using  ld = long double;
using namespace std;

// 標準入出力
struct inp {
    size_t sz;
    inp(size_t _sz = 1) : sz(_sz) {}
    template <typename T> operator T () const { T a; cin >> a; return a; }
    template <typename T> operator vector<T> () const { vector<T> a(sz); for (size_t i = 0; i < sz; i++) cin >> a[i]; return a; }
    template <typename T, typename U> operator pair<T, U> () const { T f; U s; cin >> f >> s; return pair<T, U>(f, s); }
};
inp inp1; // input one
template <typename T> void say(T &x, char end = '\n') { cout << x << end; }
template <typename T> void say(vector<T> &x, char sep = ' ', char end = '\n') { for (size_t i = 0, sz = x.size(); i < sz; i++) { cout << x[i] << (i == sz-1 ? end : sep); } }

// モジュール


// 処理内容
int main() {
    
    ios::sync_with_stdio(false); // stdioを使うときはコメントアウトすること
    cin.tie(nullptr);            // インタラクティブ問題ではコメントアウトすること
    
    ll n = inp1;
    ll m = inp1;
    cout << Yes(n == m) << endl;
    
}