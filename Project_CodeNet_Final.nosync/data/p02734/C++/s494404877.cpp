#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
const int INF = 1e8;
// const ll INF = 1LL << 60;
typedef pair<int, int> P;

// const int mod = 1000000007;
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

ll N, S;
vector<ll> A;

mint dp[3010][3010][3];

int main() {
    cin >> N >> S;
    A.resize(N);

    mint ans = 0;

    rep(i, N) cin >> A[i];

    dp[0][0][0] = 1;
    // 0: LもRも決まっていない
    // 1: L は決まった
    // 2: L、Rが決まった

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            // 配らない
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j][1] += dp[i][j][1];
            dp[i + 1][j][2] += dp[i][j][2];

            // 配る
            if (j + A[i] <= S) {
                // from 0 
                dp[i + 1][j + A[i]][1] += dp[i][j][0] * (i + 1);
                dp[i + 1][j + A[i]][2] += dp[i][j][0] * (i + 1) * (N - i);

                // from 1 
                dp[i + 1][j + A[i]][1] += dp[i][j][1];
                dp[i + 1][j + A[i]][2] += dp[i][j][1] * (N - i);
            } 
        }
    }
    ans = dp[N][S][2];

    cout << ans << endl;
}