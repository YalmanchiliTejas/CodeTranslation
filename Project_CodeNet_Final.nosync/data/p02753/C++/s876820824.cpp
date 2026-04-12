#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#if __cplusplus >= 201103L
#include <chrono>
using namespace std::chrono;
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#ifdef LOCAL
#define prln(x) (cout << #x << ' ' << x << endl)
#define pr(x) (cout << #x << ' ' << x << ' ' )
#define prv(x) (cout << x << ' ')
#else
#define prln(x) 
#define pr(x)
#define prv(x)
#endif
#define clr(x) memset((x), 0, sizeof((x)))
#define clr1(x) memset((x), -1, sizeof((x)))
#define endl "\n"
#define pi acos(-1)
#define rep(i, st, ed) for (int i = (st); i <= (ed); ++i)
#define rep0(i, st, ed) for (int i = (st); i < (ed); ++i)
#define per0(i, st, ed) for (int i = (st); i > ed; --i)
#define per(i, st, ed) for (int i = (st); i >= ed; --i)
#define chmin(a, b) (a = a > b ? b : a)
#define chmax(a, b) (a = a < b ? b : a)
template<class T> void _sf(T &x) {cin >> x;}
void _sf(int &x) {scanf("%d", &x);}
void _sf(ll &x) {scanf("%lld", &x);}
void _sf(double &x) {scanf("%lf", &x);}
void _sf(char &x) {scanf(" %c", &x);}
void _sf(char *x) {scanf("%s", x);}
void sf() {}
template <class T, class...U> void sf(T & head, U&... tail) { _sf(head); sf(tail...);}
template<class T> void _out(const T &x) { cout << x; }
void _out(const int &x) { printf("%d", x); }
void _out(const ll &x) { printf("%lld", x); }
void _out(const double &x) { printf("%.16f", x); }
void _out(const char &x) { putchar(x); }
void _out(const char *x) { printf("%s", x); }
template<class T,class U> void _out(const pair<T,U> &x) {_out(x.F); putchar(' '); _out(x.S);}
template<class T> void _out(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _out(*i++)) if (i != x.cbegin()) putchar(' '); }
void out() {}
template<class T, class... U> void out(const T &head, const U &... tail) { _out(head); putchar(sizeof...(tail) ? ' ' : '\n'); out(tail...); }
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}


int main(){
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    string s;
    bool ok = false;
    cin >> s;
    if (s[0] == 'B' && s[1] == 'B' && s[2] == 'B') {
        ok = false;
    }else if (s[0] == 'A' && s[1] == 'A' && s[2] == 'A') {
        ok = false;
    }else ok = true;
    if (ok) puts("Yes");
    else puts("No");
    return 0;
}