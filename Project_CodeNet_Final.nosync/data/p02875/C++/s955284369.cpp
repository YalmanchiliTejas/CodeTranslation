#include <bits/stdc++.h>
using namespace std;

// macros
#define overload_rep(_1, _2 ,_3 ,name, ...) name
#define re_p(i, n) for(int i = 0; i < (n); ++i)
#define r_ep(i, x, y) for(int i = (x); i <= (y); ++i)
#define rep(...) overload_rep(__VA_ARGS__, r_ep, re_p)(__VA_ARGS__)
#define all(a) a.begin(), a.end()
#ifndef STOP_DEBUG
#define debug(...)\
    do { cerr << boolalpha << "[" << #__VA_ARGS__ << "]:";\
    debug_cerr(__VA_ARGS__); cerr << noboolalpha; } while (0)
#else
#define debug(...)
#endif

// functions
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
void debug_cerr(){ cerr << '\n'; }
template<class Head, class... Tail>
void debug_cerr(Head head, Tail... tail){
    cerr << ' ' << head;
    debug_cerr(tail...);
}
template<typename T>
vector<T> make_v(size_t a, T b){ return vector<T>(a, b); }
template<typename... Ts>
auto make_v(size_t a, Ts... ts){
    return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

// cin/cout setup
struct IoSetup{
    IoSetup(){
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} iosetup;

// libraries
template<const int_fast64_t mod = 1000000007>
struct ModInt{
private: using ll = int_fast64_t;
public: ll x;
    inline constexpr ModInt(ll t = 0) noexcept : x((t %= mod) < 0 ? t + mod : t) {}
    inline constexpr friend istream& operator >> (istream& s, ModInt& m) noexcept {
        s >> m.x; m.x %= mod; if(m.x < 0)m.x += mod; return s;
    }
    inline constexpr friend ostream& operator << (ostream& s, ModInt m) noexcept {
        return s << m.x;
    }
    inline constexpr ModInt operator + (const ModInt m) noexcept { return ModInt(*this) += m; }
    inline constexpr ModInt& operator += (const ModInt m) noexcept {
        if((x += m.x) >= mod)x -= mod; return *this;
    }
    inline constexpr ModInt operator - (const ModInt m) noexcept { return ModInt(*this) -= m; }
    inline constexpr ModInt& operator -= (const ModInt m) noexcept {
        if((x += mod - m.x) >= mod)x -= mod; return *this;
    }
    inline constexpr ModInt operator * (const ModInt m) noexcept { return ModInt(*this) *= m; }
    inline constexpr ModInt& operator *= (const ModInt m) noexcept {
        x = x * m.x % mod; return *this;
    }
    inline constexpr ModInt operator / (const ModInt m) noexcept { return ModInt(*this) /= m; }
    inline constexpr ModInt& operator /= (const ModInt m) noexcept {
        return *this *= m.inv();
    }
    inline constexpr ModInt inv() const noexcept {
        ll a = x, b = mod, u = 1, v = 0, t = 0;
        while(b){ t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v); }
        return ModInt(u);
    }
    inline constexpr ModInt pow(ll p) noexcept {
        ModInt res(1), mult(*this);
        for(; p; p >>= 1){ if(p & 1)res *= mult; mult *= mult; }
        return res;
    }
};

template<const int_fast64_t mod = 1000000007>
struct ModFact{
private:
    using mint = ModInt<mod>;
    vector<mint> fact, ifact;
public:
    inline constexpr ModFact(const int sz = 200000) noexcept : fact(sz + 1), ifact(sz + 1) {
        fact[0] = mint(1);
        for(int i = 1; i <= sz; ++i)fact[i] = fact[i - 1] * mint(i);
        ifact[sz] = fact[sz].inv();
        for(int i = sz; i > 0; --i)ifact[i - 1] = ifact[i] * mint(i);
    }
    inline constexpr mint operator [] (const int id) noexcept { return fact[id]; }
    inline constexpr mint operator () (const int n, const int r) noexcept {
        return fact[n] * ifact[n - r] * ifact[r];
    }
    inline constexpr mint nPr(const int n, const int r) noexcept {
        return fact[n] * ifact[r];
    }
};

// declarations
using mint = ModInt<998244353>;
using mfact = ModFact<998244353>;
mfact fac(10000000);

// solve
int main(){

    int N, N2;
    cin >> N;
    N2 = N >> 1;

    mint sum(0), now = mint(2).pow(N), two = mint(2).inv();

    rep(i, 0, N){
        if(i > N2)sum += now * fac(N, i);
        now *= two;
    }

    cout << mint(3).pow(N) - sum * mint(2) << '\n';
    return 0;

}
