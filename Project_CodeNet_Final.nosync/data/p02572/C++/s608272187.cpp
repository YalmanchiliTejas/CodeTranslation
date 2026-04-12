#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
using ll = long long;
#define int ll
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
#define IOS\
    ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SORT(name) sort(name.begin(), name.end())
#define RSORT(name)\
    SORT(name);\
    reverse(all(name));
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
template <class T> inline void print(T x){ cout << x << '\n';}
template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
#pragma endregion

#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const int MOD = 1000000007;
// 自動で余りを取ってくれる整数型
// 割り算や負の数による初期化も可能
template< int mod >
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }
    static int get_mod() { return mod; }
};
using modint = ModInt< MOD >;

template< typename T >
class CumulativeSum
{
public:
    CumulativeSum() {}
    CumulativeSum(int sz) : m_Data(sz, T(0)) {};

    void Init(int sz) { m_Data.assign(sz, T(0)); }

    // k に x を加える O(1)
    void Add(int k, T x) {
        assert(static_cast<int>(m_Data.size()) >= k);
        if(static_cast<int>(m_Data.size()) <= k) { m_Data.push_back(x); }
        else { m_Data[k] = (m_Data[k] + x); }
    }

    // 累積和の構築 O(m_Data.size())
    void Build() {
        for(int i = 1; i < static_cast<int>(m_Data.size()); i++) {
            m_Data[i] = (m_Data[i] + m_Data[i - 1]);
        }
    }

    // 区間 [0, k] の和を返す O(1)
    // 閉区間なので k が含まれることに注意
    T Query(int k) {
        if(k < 0) { return T(0); }
        return (m_Data[min(k, static_cast<int>(m_Data.size()) - 1)]);
    }

    // 区間 [l, h] の和を返す O(1)
    // 閉区間なので k が含まれることに注意
    T Query(int l, int h) {
        return (this->Query(h) - this->Query(l-1));
    }
private:
    vector< T > m_Data;
};

const int MAX_N = 100010;

signed main() {
    IOS;

    int N;
    cin >> N;
    V<> A(N);
    REP(i, N) { cin >> A[i]; }

    CumulativeSum<modint> cs(N);
    REP(i, N) {
        cs.Add(i, modint(A[i]));
    }
    cs.Build();
    modint ans(0);
    REP(i, N) {
        modint cand = modint(A[i]) * cs.Query(i + 1, N - 1);
        ans += cand;
    }
    print(ans.x);

    return 0;
}
