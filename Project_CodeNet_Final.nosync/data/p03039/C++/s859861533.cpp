#include "bits/stdc++.h"
#define rep(i,b) for(ll i=0;i<b;i++)
#define ll long long
using namespace std;
/*--Input//////////////////////////////////////////////////*/
inline void IN(void){return;}
template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
    cin >> first;
    IN(rest...);
    return;
}
#define SS(T, ...)      T __VA_ARGS__; IN(__VA_ARGS__);
#define SV(type,c,n) vector<type> c(n);for(auto& i:c)cin >> i;
/*--Output/////////////////////////////////////////////////*/
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
inline int p(void){cout << endl; return 0;}
template<class Head> int p(Head&& head){cout << head;p();return 0;} template<class Head,class... Tail> int p(Head&& head,Tail&&... tail){cout<<head<<" ";p(forward<Tail>(tail)...);return 0;}
struct ProconInit {
    static constexpr int IOS_PREC = 15;
    static constexpr bool AUTOFLUSH = false;

    ProconInit() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(IOS_PREC);
        if(AUTOFLUSH)
            cout << unitbuf;
    }
} PROCON_INIT;


#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define debug(x) cerr<<#x<<" "<<x<<'\n';
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL<<(n))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
bool cmp(pair<ll,ll> a, pair<ll,ll> b) { return a.second < b.second; }

const int MOD = 1000000007;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


//const int MOD = 1000000007;

template< int MODULO > struct ModInt {
    using int64 = long long;
    using uint32 = unsigned int;
    using uint64 = unsigned long long;
    uint64 x; ModInt() : x(0) {}
    ModInt(int64 y) : x(set(y % MODULO + MODULO)) {}
    static uint64 set(const int64 &y) { return (y < MODULO) ? y : y - MODULO; }
    static ModInt make(const uint64 &y) { ModInt ret = y; return ret; }
    ModInt operator+(const ModInt &m) const { return make(set(x + m.x)); }
    ModInt operator-(const ModInt &m) const { return make(set(x + MODULO - m.x)); }
    ModInt operator*(const ModInt &m) const { return make(x * m.x % MODULO); }
    ModInt operator/(const ModInt &m) const { return make(x) * ~make(m.x); }
    ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
    ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
    ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
    ModInt &operator^=(const uint64 &y) { return *this = *this ^ y; }
    ModInt operator~ () const { return *this ^ (MODULO - 2); }
    ModInt operator- () const { return make(set(MODULO - x)); }
    ModInt operator! () const { return getFact(uint32(*this)); }
    ModInt operator& () const { return getFinv(uint32(*this)); }
    ModInt operator++() { return *this = make(set(x + 1)); }
    ModInt operator--() { return *this = make(set(x + MODULO - 1)); }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator< (const ModInt &m) const { return x <  m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator> (const ModInt &m) const { return x >  m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator   bool() const { return x; }
    explicit operator uint64() const { return x; }
    ModInt operator^(uint64 y) const {
        uint64 t = x, u = 1;
        while (y) { if (y & 1) (u *= t) %= MODULO; (t *= t) %= MODULO; y >>= 1; }
        return make(u);
    }
    friend ostream &operator<<(ostream &os, const ModInt< MODULO > &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt< MODULO > &m) { uint64 y; is >> y; m = make(y); return is; }
    static vector< ModInt > fact, finv, invs;
    static void init(uint32 n) {
        uint32 m = fact.size();
        if (n < m) return;
        fact.resize(n + 1, 1);
        finv.resize(n + 1, 1);
        invs.resize(n + 1, 1);
        if (m == 0) m = 1;
        for (uint32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * ModInt(i);
        finv[n] = ModInt(1) / fact[n];
        for (uint32 i = n; i >= m; --i) finv[i - 1] = finv[i] * make(i);
        for (uint32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
    }
    static ModInt getFact(uint32 n) { init(n); return fact[n]; }
    static ModInt getFinv(uint32 n) { init(n); return finv[n]; }
    static ModInt getInvs(uint32 n) { init(n); return invs[n]; }
    static ModInt C(int64 n, int64 r) {
        if (r == 0) return make(1);
        if (r <  0) return make(0);
        if (n <  0) return make(r & 1 ? MODULO - 1 : 1) * C(-n + r - 1, r);
        if (n == 0 || n < r) return make(0);
        init(n);
        return fact[n] * finv[n - r] * finv[r];
    }
    //N<=10^5を超えるが,k<=10^5の時にO(k)で求める
    static ModInt CbyK(int64 n, int64 k){
        ModInt res=1;
        rep(i,k){
            res*=n-i;
            res/=i+1;
        }
        return res;
    }
    static ModInt P(int64 n, int64 r) {
        if (n < r || r < 0) return make(0);
        init(n);
        return fact[n] * finv[n - r];
    }
    static ModInt H(int64 n, int64 r) {
        if (n < 0 || r < 0) return make(0);
        if (!n && !r) return make(1);
        init(n + r - 1);
        return C(n + r - 1, r);
    }
    static ModInt montmort(uint32 n) {
        ModInt res;
        init(n);
        for (uint32 k = 2; k <= n; ++k) {
            if (k & 1) res -= finv[k];
            else res += finv[k];
        }
        return res *= fact[n];
    }
    static ModInt LagrangePolynomial(vector<ModInt> &y, ModInt t) {
        uint32 n = y.size() - 1;
        if (t.x <= n) return y[t.x];
        init(n + 1);
        ModInt res, num(1);
        for (uint32 i = 0; i <= n; ++i) num *= t - make(i);
        for (uint32 i = 0; i <= n; ++i) {
            ModInt tmp = y[i] * num / (t - make(i)) * finv[i] * finv[n - i];
            if ((n - i) & 1) res -= tmp;
            else res += tmp;
        }
        return res;
    }
};
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::fact = vector<ModInt< MODULO >>();
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::finv = vector<ModInt< MODULO >>();
template< int MODULO >
vector<ModInt< MODULO >> ModInt< MODULO >::invs = vector<ModInt< MODULO >>();
using modint = ModInt< MOD >;

/*
・ModInt
[備考] Mod演算のための構造体
[使用例]
modint M;           // 剰余系MOD(1e9+7)における演算ができる
ModInt<mod> N;      // 剰余系modにおける演算ができる
名前空間 modint::にいくつかの関数あり
*/

int main() {
    SS(ll,N,M,K);
    modint sum = 0;
    rep(i,N)rep(j,M){
            modint tmp = (N - i) * (M - j) * (i + j);
            if (i != 0 && j != 0) tmp *= 2;
            sum += tmp;
    }
    p(sum * modint::C(N*M-2, K-2));
}