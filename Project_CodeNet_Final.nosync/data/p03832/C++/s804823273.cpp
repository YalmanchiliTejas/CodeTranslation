#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1ll << 60;
const int MOD = 1e9 + 7;
#define dump(x)                             \
    if (dbg) {                              \
        cerr << #x << " = " << (x) << endl; \
    }
#define overload4(_1, _2, _3, _4, name, ...) name
#define FOR1(n) for (ll i = 0; i < (n); ++i)
#define FOR2(i, n) for (ll i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    } else
        return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    } else
        return 0;
}
void Yes(bool flag = true) {
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void No(bool flag = true) {
    Yes(!flag);
}
void YES(bool flag = true) {
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void NO(bool flag = true) {
    YES(!flag);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int, int>>
#define vvp vector<vector<pair<int, int>>>
#define pi pair<int, int>
//#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define itn int
#define asn ans
bool dbg = false;

template <uint MD>
struct ModInt {
    using M = ModInt;
    const static M G;
    uint v;
    ModInt(ll _v = 0) { set_v(_v % MD + MD); }
    M& set_v(uint _v) {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M& r) const { return M().set_v(v + r.v); }
    M operator-(const M& r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M& r) const { return M().set_v(ull(v) * r.v % MD); }
    M operator/(const M& r) const { return *this * r.inv(); }
    M& operator+=(const M& r) { return *this = *this + r; }
    M& operator-=(const M& r) { return *this = *this - r; }
    M& operator*=(const M& r) { return *this = *this * r; }
    M& operator/=(const M& r) { return *this = *this / r; }
    bool operator==(const M& r) const { return v == r.v; }
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
    friend istream& operator>>(istream& is, M& r) { return is >> r.v; }
};
using Mint = ModInt<MOD>;
const int MN = 1'000'000;
Mint fact[MN], iFac[MN];

void first() {
    fact[0] = Mint(1);
    for (int i = 1; i < MN; i++)
        fact[i] = fact[i - 1] * Mint(i);
    iFac[MN - 1] = fact[MN - 1].inv();
    for (int i = MN - 1; i >= 1; i--) {
        iFac[i - 1] = iFac[i] * Mint(i);
    }
    assert(fact[2345] * iFac[2345] == Mint(1));
}

int N, A, B, C, D;
Mint dp[2000][2000];

void solve() {
    first();
    dp[N][A - 1] = fact[N];
    for (int x = N; x >= 1; x--) {
        for (int i = A; i <= B; i++) {
            dp[x][i] += dp[x][i - 1];
            if (x - i * C < 0)
                break;
            for (int f = C; f <= D; f++) {
                if (x - i * f < 0)
                    break;
                dp[x - i * f][i] += dp[x][i - 1] * iFac[i].pow(f) * iFac[f];
            }
        }
    }
    /*
    for (int x = N; x >= 0; x--) {
        for (int y = A - 1; y <= B; y++) {
            cout << x << " , " << y << " : " << dp[x][y] << endl;
        }
        cout << endl;
    }
    */

    Mint ans = 0;
    FOR(i, A, B + 1)
    ans += dp[0][i];
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> A >> B >> C >> D;


    solve();
    return 0;
}
