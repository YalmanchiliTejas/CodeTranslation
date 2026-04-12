#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 100000;
ll const MOD = 1000000007;

struct mint {
    ll x;  // typedef long long ll;
    mint(ll x = 0) : x((x % MOD + MOD) % MOD) {}

    mint operator-() const { return mint(-x); }

    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint& operator-=(const mint a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }

    mint operator+(const mint a) const { return mint(*this) += a; }

    mint operator-(const mint a) const { return mint(*this) -= a; }

    mint operator*(const mint a) const { return mint(*this) *= a; }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(MOD - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};

istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

// 桁DPの遷移
// N=63435 について、
// dp[3][true]  : 634○○未満となる数(00000 - 63399)についての暫定の答え
// dp[3][false] : 634○○ となる数(63400 ~ 63429)についての暫定の答え

// dp[i][true] から dp[i+1][true]にのみ遷移
// (i桁目まででNより小さいなら、i+1桁目をどのように選んでもNより小さい）
// dp[i][false] から dp[i+1][true]へ遷移
// (i桁目までNと同じで、 i+1桁目はNより小さい数の時)
// dp[i][false] から dp[i+1][false]へ遷移
// (i桁目までNと同じで、 i+1桁目もNと同じ数の時)

// 例:
// https://atcoder.jp/contests/tdpc/tasks/tdpc_number

// N = 63435のとき
// dp[0][T] = 0xxxx, 1xxxx, 2xxxx, 3xxxx, 4xxxx, 5xxxx
// dp[0][F] = 6xxxx

// Dで割った余りを求める: D=4とおく
// dp[1][T][0] = 2 (0xxxx, 4xxxx)
// dp[1][T][1] = 1 (1xxxx, 5xxxx)
// dp[1][T][2] = 1 (2xxxx)
// dp[1][T][3] = 1 (3xxxx)
// dp[1][F][0] = 0
// dp[1][F][1] = 0
// dp[1][F][2] = 1 (6xxxx)
// dp[1][F][3] = 0

// dp[2][T] = 00000-62999
// dp[2][F] = 63xxx
// dp[2][T][(j+k)%D] += dp[2][T][j] (k=0,1,...,9)
// - dp[2][T][0] = 3 * dp[1][T][0] (00xxx, 04xxx, 08xxx)
//               + 2 * dp[1][T][1] (13xxx, 17xxx)
//               + 2 * dp[1][T][2] (22xxx, 26xxx)
//               + 3 * dp[1][T][3] (31xxx, 35xxx, 39xxx)
//               +     dp[1][F][2] (62xxx)
// - dp[2][F][0] = 0 (63xxx)
// - dp[2][F][1] = 1 (63xxx)

int main() {
    ll D;
    string K;
    cin >> K >> D;

    ll n = K.length();
    mint dp[n + 5][2][D + 5];
    dp[0][0][0] = 1;

    rep(i, n) {
        rep(j, D) {
            rep(k, 10) { dp[i + 1][1][(j + k) % D] += dp[i][1][j]; }

            int ni = K[i] - '0';
            rep(k, ni) { dp[i + 1][1][(j + k) % D] += dp[i][0][j]; }

            dp[i + 1][0][(j + ni) % D] = dp[i][0][j];
        }
    }

    cout << dp[n][0][0] + dp[n][1][0] - 1 << endl;

    return 0;
}
