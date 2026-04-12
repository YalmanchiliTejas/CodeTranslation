#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for(int i=a; i<=(int)(b); i++)
#define ALL(x) begin(x),end(x)
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

template<class T> inline bool chmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}

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

const int MOD=998244353;
using mint=ModInt<MOD>;
// }}}

const int N=3005;
int A[N];
int n, S;
mint ans=0;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> S;
    REP(i,n) cin >> A[i];

    vector<mint> dp(N,0);
    // dp[0]=1;
    REP(i,n) {
        vector<mint> ndp=dp;
        ndp[A[i]]+=i+1;
        REP1(j,A[i],S) {
            ndp[j]+=dp[j-A[i]];
        }
        dp=ndp;
        ans+=dp[S];
    }
    cout << ans << '\n';
    return 0;
}
