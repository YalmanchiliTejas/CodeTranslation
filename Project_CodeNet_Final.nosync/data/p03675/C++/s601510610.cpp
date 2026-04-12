#include <bits/stdc++.h>
using namespace std;

/* template {{{ */
/* vim: set foldmethod=marker: */
/* Roadagain {{{ */
/****************************************************************************************/
/*                                                                                      */
/*                                                                                      */
/*                                                                                      */
/*  /#######                            /##                               /##           */
/* | ##__  ##                          | ##                              |__/           */
/* | ##  \ ##  /######   /######   /#######  /######   /######   /######  /## /#######  */
/* | #######/ /##__  ## |____  ## /##__  ## |____  ## /##__  ## |____  ##| ##| ##__  ## */
/* | ##__  ##| ##  \ ##  /#######| ##  | ##  /#######| ##  \ ##  /#######| ##| ##  \ ## */
/* | ##  \ ##| ##  | ## /##__  ##| ##  | ## /##__  ##| ##  | ## /##__  ##| ##| ##  | ## */
/* | ##  | ##|  ######/|  #######|  #######|  #######|  #######|  #######| ##| ##  | ## */
/* |__/  |__/ \______/  \_______/ \_______/ \_______/ \____  ## \_______/|__/|__/  |__/ */
/*                                                    /##  \ ##                         */
/*                                                   |  ######/                         */
/*                                                    \______/                          */
/*                                                                                      */
/****************************************************************************************/
/* }}} */
/* constant {{{ */
const int    INF = (int)1e9;
const int    MOD = (int)1e9 + 7;
const double PI  = acos(-1);
const double EPS = 1e-14;
/* }}} */
/* alias {{{ */
template <class T> using vec = vector<T>;
using ll   = long long;
using ull  = unsigned long long;
using vi   = vec<int>;
using vl   = vec<ll>;
using vd   = vec<double>;
using pii  = pair<int, int>;
using pdd  = pair<double, double>;
using vec2 = complex<double>;
/* }}} */
/* repetition {{{ */
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define RFOR(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPIT(i, obj) for (auto i = (obj).begin(); i != (obj).end(); ++i)
#define RREPIT(i, obj) for (auto i = (obj).rbegin(); i != (obj).rend(); ++i)
/* }}} */
/* short {{{ */
#define pb emplace_back
#define mp make_pair
#define fst first
#define sec second
/* }}} */
/* input {{{ */
template <class T = int> inline T in(){ T x; cin >> x; return x; }
template <class T = int> inline vec<T> in(int n){ vec<T> v(n); REP(i, n) v[i] = in<T>(); return v; }
template <class T = int> inline void in(T* x, int n){ REP(i, n) x[i] = in<T>(); }
#define inl in<ll>
#define ind in<double>
#define ins in<string>
/* }}} */
/* container util {{{ */
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLA(ary, n) (ary), ((ary) + (n))
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define SZ(obj) (obj).size()
#define SZA(ary) (sizeof(ary) / sizeof(*ary))
#define SORT(obj) sort(ALL(obj))
#define SORTA(ary, n) sort(ALLA(ary, n))
#define EXIST(obj, key) ((obj).find(key) != (obj).end())
#define CLEARY(ary) memset((ary), 0, sizeof(ary))
/* }}} */
/* print util {{{ */
template <class T> inline void print(const T& x){ cout << x << '\n'; }
template <class T> inline void printd(const T& x, int d){ cout << fixed << setprecision(d) << x << '\n'; }
template <class T> inline void printv(vec<T>& v){ int n = SZ(v); REP(i, n) cout << v[i] << "\n "[i < n - 1]; }
template <class T> inline void printv(vec<T>& v, int n){ REP(i, n) cout << v[i] << "\n "[i < n - 1]; }
template <class T> inline void printa(T* ary, int n){ REP(i, n) cout << ary[i] << "\n "[i < n - 1]; }
#define DUMP(x) cerr << #x << ": " << (x) << '\n'
#define DEBUG(x) cerr << #x << ": " << (x) << " (" << __LINE__ << ")" << '\n'
/* }}} */
/* template }}} */

signed main()
{
    int n = in();
    vi a = in(n);

    for (int i = n - 1; i > 0; i -= 2){
        printf("%d ", a[i]);
    }
    printf("%d", a[0]);
    for (int i = 2 - n % 2; i < n; i += 2){
        printf(" %d", a[i]);
    }
    puts("");

    return 0;
}
