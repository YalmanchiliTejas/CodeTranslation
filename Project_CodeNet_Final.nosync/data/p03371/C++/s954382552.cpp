// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep4(i, a, b, c) for (int i = int(a), i##__b = int(b), i##__c = int(c); i < i##__b; i += i##__c)
#define rep1(n) rep4(i, 0, n, 1)
#define rep2(i, n) rep4(i, 0, n, 1)
#define rep3(i, a, b) rep4(i, a, b, 1)
#define REP(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep3(i, a, b) for (int i = int(b) - 1, i##__a = int(a); i >= i##__a; i--)
#define rrep1(n) rrep3(i, 0, n)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep4(i, a, b, c) for (int i = int(a + (b - a - 1) / c * c), i##__a = int(a), i##__c = int(c); i >= i##__a; i -= i##__c)
#define RREP(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define FOREACH(i, x) for (auto &i : x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define mt make_tuple
// #define print(x) cout << x << endl;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using vstring = vector<string>;
template <class T> using vv = vector<vector<T>>;
#define vvint(A, H, W) vvint A(H, vint(W))
template <class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return 1;}return 0;}
template <class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return 1;}return 0;}
// IO

inline int scan(){ return getchar(); }
inline void scan(int &a){ scanf("%d", &a); }
// inline void scan(unsigned &a){ scanf("%u", &a); }
// inline void scan(long &a){ scanf("%ld", &a); }
inline void scan(long long &a){ scanf("%lld", &a); }
// inline void scan(unsigned long long &a){ scanf("%llu", &a); }
inline void scan(char &a){ cin >> a; }
// inline void scan(float &a){ scanf("%f", &a); }
inline void scan(double &a){ scanf("%lf", &a); }
inline void scan(long double &a){ scanf("%Lf", &a); }
inline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size(); i++) { int a; scan(a); vec[i] = a; } }
inline void scan(char a[]){ scanf("%s", a); }
inline void scan(string &a){ cin >> a; }
template<class T> inline void scan(vector<T> &vec);
template<class T, size_t size> inline void scan(array<T, size> &vec);
template<class T, class L> inline void scan(pair<T, L> &p);
template<class T, size_t size> inline void scan(T (&vec)[size]);
template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(deque<T> &vec){ for(auto &i : vec) scan(i); }
template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto &i : vec) scan(i); }
template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(T &a){ cin >> a; }
inline void in(){}
template <class Head, class... Tail> inline void in(Head &head, Tail&... tail){ scan(head); in(tail...); }
inline void print(){ putchar(' '); }
inline void print(const bool &a){ printf("%d", a); }
inline void print(const int &a){ printf("%d", a); }
// inline void print(const unsigned &a){ printf("%u", a); }
// inline void print(const long &a){ printf("%ld", a); }
inline void print(const long long &a){ printf("%lld", a); }
inline void print(const unsigned long long &a){ printf("%llu", a); }
inline void print(const char &a){ printf("%c", a); }
inline void print(const char a[]){ printf("%s", a); }
inline void print(const float &a){ printf("%.15f", a); }
inline void print(const double &a){ printf("%.15f", a); }
inline void print(const long double &a){ printf("%.15Lf", a); }
inline void print(const string &a){ for(auto&& i : a) print(i); }
template<class T> inline void print(const vector<T> &vec);
template<class T, size_t size> inline void print(const array<T, size> &vec);
// template<class T, class L> inline void print(const pair<T, L> &p);
template<class T, size_t size> inline void print(const T (&vec)[size]);
template<class T> inline void print(const vector<T> &vec){ if(vec.empty()) return; print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const deque<T> &vec){ if(vec.empty()) return; print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> inline void print(const array<T, size> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> inline void print(const pair<T, L> &p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> inline void print(const T (&vec)[size]){ print(vec[0]); for(auto i = vec; ++i != end(vec); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const T &a){ cout << a; }
inline int out(){ putchar('\n'); return 0; }
template<class T> inline int out(const T &t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> inline int out(const Head &head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
inline int first(bool i = true){ return out(i?"first":"second"); }
inline int yes(bool i = true){ return out(i?"yes":"no"); }
inline int Yes(bool i = true){ return out(i?"Yes":"No"); }
inline int No(){ return out("No"); }
inline int YES(bool i = true){ return out(i?"YES":"NO"); }
inline int NO(){ return out("NO"); }
inline int Yay(bool i = true){ return out(i?"Yay!":":("); }
inline int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
inline int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
inline void Case(ll i){ printf("Case #%lld: ", i); }

struct Point {int x, y; Point(int x, int y):x(x), y(y){}};
int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1};
pii dvs[] = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};
// clang-format on


int main() {
    int A, B, C, X, Y;
    in(A, B, C, X, Y);
    C *= 2;
    chmin(A, C);
    chmin(B, C);
    chmin(C, A + B);
    int Z = min(X, Y);
    out(C * Z + (X - Z) * A + (Y - Z) * B);
}
