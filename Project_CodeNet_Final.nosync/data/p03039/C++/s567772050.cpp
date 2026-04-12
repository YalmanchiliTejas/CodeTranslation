#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

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

struct combination
{
    vector<mint> fact, ifact;
    combination(int n) : fact(n+1), ifact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator() (int n, int k) {
        if ( k < 0 || k > n ) return 0;
        return fact[n] * ifact[k] * ifact[n-k];
    }
} comb(500005);


int N, M, K;

int main() {
    cin >> N >> M >> K;
    mint res = 0;
    rep(i,N) {
        res += mint(i) * mint(N - i) * mint(M).pow(2);
    }
    rep(j, M) {
        res += mint(j) * mint(M - j) * mint(N).pow(2);
    }
    cout << res*comb(M*N-2, K-2) << endl;
}