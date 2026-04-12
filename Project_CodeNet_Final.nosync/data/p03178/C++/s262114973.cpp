#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

struct mint {
    constexpr static int mod = 1000000007;
    long long x;
    mint(long long x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    string k;
    ll d;
    cin >> k >> d;
    ll n = len(k);
    // dp[figures][0:just, 1:smaller][surplus] = patterns
    vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(2, vector<mint>(d, 0)));
    dp[0][0][0] = 1;
    rep(i, n) {
        ll v = k[i] - '0';
        // just
        rep(j, d) {
            dp[i + 1][0][(j + v) % d] += dp[i][0][j];
        }
        // smaller
        rep(j, d) {
            rep(l, 10) {
                dp[i + 1][1][(j + l) % d] += dp[i][1][j];
                if (l < v) {
                    dp[i + 1][1][(j + l) % d] += dp[i][0][j];
                }
            }
        }
    }
    mint ans = dp[n][0][0] + dp[n][1][0] - 1;
    cout << ans.x << endl;
    return 0;
}
