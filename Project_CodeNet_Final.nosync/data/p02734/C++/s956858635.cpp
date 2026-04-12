#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1e10;
const int MOD = 998244353;
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
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define itn int
bool dbg = false;

//Template by yosupo
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
};
using Mint = ModInt<MOD>;
//Template by yosupo
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
Mint C(int n, int k) {
    if (n < k || k < 0)
        return Mint(0);
    return fact[n] * iFac[k] * iFac[n - k];
}


int N, S, A[101010];
Mint dp[3030][3030];

void solve() {
    Mint ans = 0;

    FOR(i, 1, N + 1) {
        int a = A[i - 1];
        FOR(s, 1, S + 1) {
            if (s == a && s != S) {
                dp[i][s] = dp[i - 1][s] + i;
            } else if (s == a && s == S) {
                dp[i][s] = i;
            } else if (s == S && s - a > 0) {
                dp[i][s] = dp[i - 1][s - a];
            } else if (s - a > 0)
                dp[i][s] = dp[i - 1][s] + dp[i - 1][s - a];
            else if (s != S) {
                dp[i][s] = dp[i - 1][s];
            }
            //cerr << dp[i][s] << " ";
        }
        //cerr << endl;
    }
    FOR(i, 1, N + 1) {
        ans += dp[i][S] * (N - i + 1);
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> S;
    FOR(N)
    cin >> A[i];

    solve();
    return 0;
}
