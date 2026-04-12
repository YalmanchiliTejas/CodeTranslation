// 5/31
// 2-6-2. 双六
// 類題
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
using ll = long long;
const int mod = 1000000007;
// const int mod = 998244353;
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

// ax + by = gcd(a, b)を満たすx, yを求める。
// 戻り値はgcd(a, b)
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;  // gcd。普通のユークリッド。
    }
    ll d = extGCD(b, a % b, y, x);
    y -= a/b * x;
    return d;
}

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

mint dp[1010][1010];

int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    combination comb(10000);

    // memset(dp, mint(0), sizeof(dp));
    // for (int i = A; i <= B; i++) {
    //     dp[i][0] = 1;
    // }
    dp[A][0] = 1;

    // dp[i + 1][j] = i人目までのグループでj人を選ぶ組み合わせ
    // vector<vector<mint>> dp(N + 1, vector<mint>(N + 1, mint(0)));

    // rep(i, N) {
    //     rep(j, N + 1) {
    //         rep(k, j / i + 1) {
    //             dp[i + 1][j] = dp[i][j - i * k];
    //         }
    //     }
    // }

    for (int i = A; i <= B; i++) {
        for (int j = 0; j <= N; j++) {
            // k = 0の場合
            dp[i + 1][j] += dp[i][j];

            for (int k = C; k <= D && k <= j / i; k++) {
                dp[i + 1][j] += dp[i][j - i * k] * comb.fact[N - j + i * k] * comb.ifact[N - j] * comb.fact[i].pow(k).inv() * comb.fact[k].inv();
            }
        }
    }

    cout << dp[B + 1][N].x << endl;
}
