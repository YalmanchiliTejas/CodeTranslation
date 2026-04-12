#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

const int mod = 1000000007;
struct mint {
    ll x;
    mint(ll x=0):x( (x%mod + mod) % mod ) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ( (x += a.x) >= mod ) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ( ( x += mod - a.x) >= mod ) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        ( x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) { return mint(*this) /= a; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
 
int main() {
    int n;
    cin >> n;
    vector<mint> a(n);
    vector<mint> cum_sum(n);
    rep(i,n) { 
        cin >> a[i];
        cum_sum[i] = a[i];
    }
    mint res = 0;
    for (int i = 1; i < n; ++i) cum_sum[i] += cum_sum[i-1];
    rep(i,n-1) {
        res += a[i] * (cum_sum[n-1] - cum_sum[i]);
    } 
    cout << res << endl;
    return 0;
}