//header
#ifdef LOCAL
    #include "cxx-prettyprint-master/prettyprint.hpp"
    #define debug(x) cout << x << endl
#else
    #define debug(...) 42
#endif
    #pragma GCC optimize("Ofast")
    #include <bits/stdc++.h>
    //types
    using namespace std;
    using ll = long long;
    using ld = long double;
    typedef pair < ll , ll > Pl;
    typedef pair < int, int > Pi;
    typedef vector<ll> vl;
    typedef vector<int> vi;
    template< typename T >
    using mat = vector< vector< T > >;
    template< int mod >
    struct modint {
        int x;

        modint() : x(0) {}

        modint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

        modint &operator+=(const modint &p) {
            if((x += p.x) >= mod) x -= mod;
            return *this;
        }

        modint &operator-=(const modint &p) {
            if((x += mod - p.x) >= mod) x -= mod;
            return *this;
        }

        modint &operator*=(const modint &p) {
            x = (int) (1LL * x * p.x % mod);
            return *this;
        }

        modint &operator/=(const modint &p) {
            *this *= p.inverse();
            return *this;
        }

        modint operator-() const { return modint(-x); }

        modint operator+(const modint &p) const { return modint(*this) += p; }

        modint operator-(const modint &p) const { return modint(*this) -= p; }

        modint operator*(const modint &p) const { return modint(*this) *= p; }

        modint operator/(const modint &p) const { return modint(*this) /= p; }

        bool operator==(const modint &p) const { return x == p.x; }

        bool operator!=(const modint &p) const { return x != p.x; }

        modint inverse() const {
            int a = x, b = mod, u = 1, v = 0, t;
            while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
            }
            return modint(u);
        }

        modint pow(int64_t n) const {
            modint ret(1), mul(x);
            while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
            }
            return ret;
        }

        friend ostream &operator<<(ostream &os, const modint &p) {
            return os << p.x;
        }

        friend istream &operator>>(istream &is, modint &a) {
            int64_t t;
            is >> t;
            a = modint< mod >(t);
            return (is);
        }

        static int get_mod() { return mod; }
    };
    //abreviations
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define rep_(i, a_, b_, a, b, ...) for (int i = (a), max_i = (b); i < max_i; i++)
    #define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
    #define rev(i,n) for(int i=n-1;i>=0;i--)
    #define SZ(x) ((ll)(x).size())
    #define pb(x) push_back(x)
    #define eb(x) emplace_back(x)
    #define ff first
    #define ss second
    #define mp make_pair
    #define print(x) cout << x << endl
    //functions
    ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
    template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
    template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    template< typename T >
    T mypow(T x, ll n) {
        T ret = 1;
        while(n > 0) {
            if(n & 1) (ret *= x);
            (x *= x);
            n >>= 1;
        }
        return ret;
    }
    ll modpow(ll x, ll n, const ll mod) {
        ll ret = 1;
        while(n > 0) {
            if(n & 1) (ret *= x);
            (x *= x);
            n >>= 1;
            x%=mod;
            ret%=mod;
        }
        return ret;
    }
    uint64_t my_rand(void) {
        static uint64_t x = 88172645463325252ULL;
        x = x ^ (x << 13); x = x ^ (x >> 7);
        return x = x ^ (x << 17);
    }
    //graph template
    template< typename T >
    struct edge {
        int src, to;
        T cost;

        edge(int to, T cost) : src(-1), to(to), cost(cost) {}

        edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

        edge &operator=(const int &x) {
            to = x;
            return *this;
        }
        operator int() const { return to; }
    };

    template< typename T >
    using Edges = vector< edge< T > >;
    template< typename T >
    using WeightedGraph = vector< Edges< T > >;
    using UnWeightedGraph = vector< vector< int > >;

//constant
#define INF 1000000000000000LL
#define mod 998244353LL
typedef modint<mod> mint;
#define eps 0.0000000000008
//library

//main
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    ll n, s; cin>>n>>s;
    vl a(n);
    rep(i, n)cin>>a[i];
    mat<mint> dp(n+1, vector<mint>(s+1, 0));
    dp[0][0] = 1;
    rep(i, n)rep(j, s+1){
        dp[i+1][j]+=dp[i][j];
        if(j+a[i]>s)continue;
        if(j == 0)dp[i+1][j+a[i]] += i+1;
        else dp[i+1][j+a[i]] += dp[i][j];
    }
    mint ans=0;
    rep(i, n){
        ans+=dp[i+1][s];
    }
    print(ans);
}