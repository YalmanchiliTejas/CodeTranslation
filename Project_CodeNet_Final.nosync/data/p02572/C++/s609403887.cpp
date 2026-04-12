// {{{ by unolight
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
// }}}

// {{{ ModInt
template<int _MOD>
struct ModInt {
    static const auto MOD = _MOD;
    template<class T> using integral_only = typename enable_if<is_integral<T>::value>::type;

    int x;   
    constexpr ModInt() : x() {}

    template<class T, integral_only<T>* = nullptr>
    ModInt(T _x=0) {
        x = _x % MOD;
        if(x<0) x+=MOD;
    }
    ModInt operator-() const { return {x == 0? 0 : MOD-x}; }
    ModInt& operator+=(const ModInt a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt a) {
        x = (long long)x * a.x % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt a) {
        return (*this) *= a.inv();
    }

    ModInt operator+(const ModInt a) const { return ModInt(*this) += a; }
    ModInt operator-(const ModInt a) const { return ModInt(*this) -= a; }
    ModInt operator*(const ModInt a) const { return ModInt(*this) *= a; }
    ModInt operator/(const ModInt a) const { return ModInt(*this) /= a; }
    ModInt inv() const {
        // for prime MOD
        return pow(MOD-2);
    }
    ModInt inv2() const {
        // work for non-prime MOD if gcd(x,MOD) = 1
        int a = x, b = MOD, u = 1, v = 0;
        while(b != 0) {
            int t = a / b;
            a -= t * b;
            u -= t * v;
            swap(a, b);
            swap(u, v);
        }
        return u;
    }
    template<class T, integral_only<T>* = nullptr>
    ModInt pow(T t) const {
        ModInt r = 1, p = *this;
        while(t) {
            if(t & 1) r *= p;
            p *= p;
            t >>= 1;
        }
        return r;
    }

    bool operator==(ModInt rhs) const { return x == rhs.x; }
    bool operator!=(ModInt rhs) const { return x != rhs.x; }
    bool operator<(ModInt rhs) const { return x < rhs.x; }
    bool operator<=(ModInt rhs) const { return x <= rhs.x; }
    bool operator>(ModInt rhs) const { return x > rhs.x; }
    bool operator>=(ModInt rhs) const { return x >= rhs.x; }

    friend string to_string(ModInt i) { return to_string(i.x); }
    friend istream& operator>>(istream&i,ModInt&a) { return i>>a.x; }
    friend ostream& operator<<(ostream&o,const ModInt&a) { return o<<a.x; }
};

const int MOD=1000000007;
using mint=ModInt<MOD>;
// }}}

void main() {
    int n;
    R(n);
    VI a(n);
    REP(i,n) R(a[i]);
    vector<mint> pref(n+1);
    REP(i,n) pref[i+1]=pref[i]+a[i];
    mint ans=0;
    REP(i,n) {
        ans+=(pref[n]-pref[i+1])*a[i];
    }
    W(ans);
}

}} // {{{ main
int main() { unolight::main(); return 0; }
// }}}