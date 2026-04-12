#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

const ll mod = 998244353;
struct mint {
    ll x;  // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    mint inv() const {
        return pow(mod - 2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

struct combination {
    vector<mint> fact, ifact;
    // init struct with "n" of "nCk" (maximum number in other words)
    combination(int n) : fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }
    // c(n,k) returns mint that contains nCk (mod p (= 1e9+7)) in x
    // i.e.) mint num = c(n,k), then num.x == nCk (mod p (= 1e9+7))
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }

    // nPk - permutation
    mint p(int n, int k) {
        return fact[n] * ifact[n - k];
    }
};

int main() {
    int n, s;
    cin >> n >> s;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    mint ans;
    vector<mint> dp(s + 1);
    rep(i,n){
        dp[0] += 1;
        vector<mint> nextdp(s + 1);
        rep(j,s+1){
            nextdp[j] += dp[j];
            if(j+a[i] <= s){
                nextdp[j + a[i]] += dp[j];
            }
        }
        dp = nextdp;
        ans += dp[s];
    }
    cout << ans.x << endl;
}