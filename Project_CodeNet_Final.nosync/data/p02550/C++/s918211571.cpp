// {{{ by unolight
#pragma region
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

namespace { namespace unolight {
// Read Input
template<class T> void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }
void R() {}
template<class T, class... U> void R( T& head, U&... tail ) { _R(head); R(tail...); }
// Write Output
template<class T> void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const int64_t &x ) { printf("%" PRId64,x); }
void _W( const double &x ) { printf("%.16f\n",x); }
void _W( const char &x ) { putchar(x); }
void _W( const char *x ) { printf("%s",x); }
template<class T> void _W( const vector<T> &x ) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W( const T& head, const U&... tail ) { _W(head); putchar(sizeof...(tail)?' ':'\n'); W(tail...); }

#ifdef UNOLIGHT
#include "dump.hpp"
#else
#define dump(...)
#endif

template<class T> inline bool chmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}
#pragma endregion
// }}}

void main() {
    LL n, x, m;
    R(n,x,m);
    map<LL,int> seen;
    vector<LL> a;
    LL me=x;
    int time=0,prv=-1;
    while (1) {
        if ( time>=n ) break;
        if ( seen.count(me) ) {
            prv=seen[me];
            break;
        }
        if ( prv==-1 ) {
            seen[me]=time++;
            a.PB(me);
            me=me*me%m;
        }
    }
    LL sum=0;
    if ( time>=n ) {
        for ( auto it:seen ) {
            sum+=it.first;
        }
        W(sum);
    } else {
        int cycle = time - prv;
        for ( int i=prv; i<time; i++ ) sum+=a[i];
        n -= prv;
        LL k = n/cycle;
        sum*=k;
        k=n%cycle;
        for ( int i=0; i<k; i++ ) sum+=a[prv+i];
        for ( int i=0; i<prv; i++ ) sum+=a[i];
        W(sum);
    }
}

}} // {{{ main
int main() { unolight::main(); return 0; }
// }}}
