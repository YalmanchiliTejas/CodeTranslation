//header
#ifdef LOCAL
    #include "cxx-prettyprint-master/prettyprint.hpp"
    #define print(x) cout << x << endl
#else
    #define print(...) 42
#endif
    #pragma GCC optimize("Ofast")
    #include <bits/stdc++.h>
    //types
    using namespace std;
    using ll = long long;
    typedef pair < ll , ll >Pl;
    typedef pair < int, int >Pi;
    typedef vector<ll> vl;
    typedef vector<int> vi;
    template< typename T >
    using mat = vector< vector< T > >;
    template <std::uint_fast64_t Modulus> class modint {
        using u64 = std::uint_fast64_t;

        public:
        u64 a;

        constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
        constexpr u64 &value() noexcept { return a; }
        constexpr const u64 &value() const noexcept { return a; }
        constexpr modint operator+(const modint rhs) const noexcept {
            return modint(*this) += rhs;
        }
        constexpr modint operator-(const modint rhs) const noexcept {
            return modint(*this) -= rhs;
        }
        constexpr modint operator*(const modint rhs) const noexcept {
            return modint(*this) *= rhs;
        }
        constexpr modint operator/(const modint rhs) const noexcept {
            return modint(*this) /= rhs;
        }
        constexpr modint &operator+=(const modint rhs) noexcept {
            a += rhs.a;
            if (a >= Modulus) {
            a -= Modulus;
            }
            return *this;
        }
        constexpr modint &operator-=(const modint rhs) noexcept {
            if (a < rhs.a) {
            a += Modulus;
            }
            a -= rhs.a;
            return *this;
        }
        constexpr modint &operator*=(const modint rhs) noexcept {
            a = a * rhs.a % Modulus;
            return *this;
        }
        constexpr modint &operator/=(modint rhs) noexcept {
            u64 exp = Modulus - 2;
            while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
            }
            return *this;
        }
        };
    //abbreviations
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define rep2(i,a,b) for(int i=(a);i<(b);++i)
    #define rep(i,n) for(int i=0;i<(n);++i)
    #define rev(i,n) for(int i=n-1;i>=0;i--)
    #define SZ(x) ((ll)(x).size())
    #define pb(x) push_back(x)
    #define ff first
    #define ss second
    #define mp make_pair
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
#define INF 1'010'000'000'000'000'017LL
#define mod 1000000007LL
typedef modint<mod> mint;
#define eps 0.000001
const double PI = M_PI;
//library
template< typename T >
struct Combination {
    vector< T > _fact, _rfact, _inv;

    Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
        _fact[0] = _rfact[sz] = _inv[0] = 1;
        for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
        _rfact[sz] /= _fact[sz];
        for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
        for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
    }

    inline T fact(int k) const { return _fact[k]; }

    inline T rfact(int k) const { return _rfact[k]; }

    inline T inv(int k) const { return _inv[k]; }

    T P(int n, int r) const {
        if(r < 0 || n < r) return 0;
        return fact(n) * rfact(n - r);
    }

    T C(int p, int q) const {
        if(q < 0 || p < q) return 0;
        return fact(p) * rfact(q) * rfact(p - q);
    }

    T H(int n, int r) const {
        if(n < 0 || r < 0) return (0);
        return r == 0 ? 1 : C(n + r - 1, r);
    }
};
Combination<mint> comb(1010);
int n, a, b, c, d;
mat<ll> memo(1010, vl(1010, -1));
mint rec(int i, int m){
    if(m<0) return 0;
    if(i == b+1 && m == 0) return 1;
    if(i == b+1 && m != 0) return 0;
    if(memo[i][m]>=0)return mint(memo[i][m]);
    mint res = rec(i+1, m);
    rep2(x, c, d+1){
        if(m-x*i<0)break;
        res+=rec(i+1, m-x*i)*comb.C(m, x*i)*comb._fact[x*i]/mypow<mint>(comb._fact[i], x)/comb._fact[x];
    }
    memo[i][m] = res.value();
    return res;
}
//main
int main(){
    cin>>n>>a>>b>>c>>d;
    cout << rec(a, n).value() << endl;
}
