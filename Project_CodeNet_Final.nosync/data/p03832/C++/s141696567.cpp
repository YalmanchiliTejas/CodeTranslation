#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)

const int mod = 1e9+7;
struct mint {
    ll x;
    mint(ll x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
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
        if (t == 0) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};
istream& operator>>(istream& i, mint& var) {
    ll tmp; i >> tmp;
    var.x = tmp;
    return i;
}
ostream& operator<<(ostream& o, const mint& var) {
    o << var.x;
    return o;
}
vector<mint> fac, fac_inv;
void init() {
    int MAX_N = 1e3+10;
    fac.assign(MAX_N,1);
    fac_inv.assign(MAX_N,1);
    for (int i = 0; i < MAX_N; ++i) {
        fac[i+1] = fac[i] * mint(i+1);
        fac_inv[i+1] = fac[i+1].inv();
    }
}
mint perm(int n, int r) {
    return fac[n] * fac_inv[n-r];
}

ll n, a, b, c, d;
mint dp[1010][1010];

int main() {
    cin >> n >> a >> b >> c >> d;
    init();
    dp[a][0] = 1;
    rng(i,a,b+1) {
        rep(j,n+1) {
            dp[i+1][j] += dp[i][j];
            rng(k,c,d+1) {
                if (j+i*k > n) break;
                mint mul = perm(n-j,i*k) * fac_inv[i].pow(k) * fac_inv[k];
                dp[i+1][j+i*k] += mul * dp[i][j];
            }
        }
    }

    mint ans = dp[b+1][n];
    cout << ans << "\n";
    return 0;
}
