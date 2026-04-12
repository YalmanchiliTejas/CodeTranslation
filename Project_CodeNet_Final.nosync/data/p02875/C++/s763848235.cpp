/*{{{*/
//#define HOME
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define F first
#define S second

template<class T> void _R(T &_x) { cin >> _x; }
void _R(int &_x) { scanf("%d", &_x); }
void _R(int64_t &_x) { scanf("%" SCNd64, &_x); }
void _R(double &_x) { scanf("%lf", &_x); }
void _R(char &_x) { scanf(" %c", &_x); }
void _R(char *_x) { scanf("%s", _x); }
template<class T, class U> void _R(pair<T, U> &_x) {_R(_x.F); _R(_x.S);}
void R() {}
template<class T, class... U> void R(T &_head, U &... _tail) { _R(_head); R(_tail...); }

template<class T> void _W(const T &_x) { cout << _x; }
void _W(const int &_x) { printf("%d", _x); }
void _W(const int64_t &_x) { printf("%" PRId64, _x); }
void _W(const double &_x) { printf("%.16f", _x); }
void _W(const char &_x) { putchar(_x); }
void _W(const char *_x) { printf("%s", _x); }
template<class T, class U> void _W(const pair<T, U> &_x) {_W(_x.F); putchar(' '); _W(_x.S);}
template<class T> void _W(const vector<T> &_x) { for (auto i = _x.begin(); i != _x.end(); _W(*i++)) if (i != _x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &_head, const U &... _tail) { _W(_head); putchar(sizeof...(_tail) ? ' ' : '\n'); W(_tail...); }
template<class T, class... U> void DB(const T &_head, const U &... _tail) {
#ifdef HOME
    W('#', _head, _tail...);
#endif
}

#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define RAN(x,n) (x).begin(), (x).begin()+(n)
#define UNIQUE(x) {sort(ALL(x)); (x).erase(unique(ALL(x)), (x).end());}

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
//#define ITER(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define IT3(i,st,ed) for (auto i = st; i != ed; ++i)
#define IT2(i,range) IT3(i,range)

#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define MS(X, v) memset((X), (v), sizeof((X)))

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

typedef int64_t ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

inline int LG (const unsigned int &_x) { return 31-__builtin_clz(_x); }  // floor: LG(x), ceil: LG(x-1)+1
/*}}}*/

const int MOD = 998244353;

int n;

/*
2 * C(n, k) * 2^(n-k), k = ceil(n/2) ... n
*/

int ADD(int a, int b){ return (a + b) % MOD; }
int MUL(int a, int b){ return (ll)a * b % MOD; }
int POW(int a, int p){
    int r = 1, t = a;
    for(; p; p >>= 1, t = MUL(t, t))
        if(p & 1) r = MUL(r, t);
    return r;
}
int INV(int a){ return POW(a, MOD-2); }

int main(){
    R(n);

    int ans = POW(3, n);
    int p2 = 1, c = 1;
    REPD(k, n, n/2+1){
        ans = ADD(ans, MOD - MUL(2 * p2, c));
        p2 = MUL(p2, 2);
        c = MUL(MUL(c, k), INV(n-k+1));
    }

    W(ans);

    return 0;
}
