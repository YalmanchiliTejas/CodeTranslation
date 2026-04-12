// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T& x, const T& y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T& x, const T& y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Mod-Int
constexpr int MOD = 1000000007;
struct ModInt {
    ll val;
    ModInt() = default;
    ModInt(ll x) : val(x % MOD + (x < 0 ? MOD : 0)) {}
    ModInt &operator+= (const ModInt &x) {if ((val += x.val) >= MOD) val -= MOD; return *this;}
    ModInt &operator-= (const ModInt &x) {if ((val -= x.val) < 0) val += MOD; return *this;}
    ModInt &operator*= (const ModInt &x) {(val *= x.val) %= MOD; return *this;}
    ModInt operator+ (const ModInt &x) const {return ModInt(*this) += x;}
    ModInt operator- (const ModInt &x) const {return ModInt(*this) -= x;}
    ModInt operator* (const ModInt &x) const {return ModInt(*this) *= x;}
    ModInt pow(ll t) const {
        if (!t) return ModInt(1);
        ModInt m = pow(t / 2);
        m *= m;
        if (t & 1) m *= *this;
        return m;
    }
    ModInt inv() const {return pow(MOD - 2);}
    ModInt &operator/= (const ModInt &x) {return *this *= x.inv();}
    ModInt operator/ (const ModInt &x) const {return ModInt(*this) /= x;}
    friend istream &operator>> (istream &is, ModInt &x) {is >> x.val; return is;}
    friend ostream &operator<< (ostream &os, const ModInt &x) {os << x.val; return os;}
};

// Main
int main() {
    string K;
    int D;
    cin >> K >> D;
    
    vector<vector<vector<ModInt>>> dp(K.size() + 1, vector<vector<ModInt>>(D, vector<ModInt>(2, ModInt(0))));
    dp[0][0][0] = ModInt(1);
    rep(i, K.size()) rep(j, D) rep(s, 2) for (int d = 0; d <= (s ? 9 : K[i] - '0'); ++d) {
        dp[i + 1][(j + d) % D][s || d < K[i] - '0'] += dp[i][j][s];
    }
    
    cout << dp[K.size()][0][0] + dp[K.size()][0][1] - ModInt(1) << "\n";
}
