#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll mod = 998244353;
const double eps = 1e-8;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

class mint {
public:
    ll x;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    ll get() const { return x; }
    mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this; }
    mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const { if (!t) return 1; mint a = pow(t>>1); return (t & 1) ? a*a*(*this) : a*a; }
    operator ll () const { return x; }
    operator string () const { return to_string(x); }
    friend istream& operator>>(istream& is, mint& a) { is>>a.x; return is; }

    // for prime mod
    mint inv() const { return pow(mod-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};

mint dp[3001][3001];

int main() {
    int N, S;
    cin >> N >> S;
    vector<ll> A(N);
    for (int i=0; i<N; ++i) cin >> A[i];

    mint res(0);
    for (int i=0; i<N; ++i) {
        dp[i][A[i]] += mint(i+1);
        for (int j=0; j<=S; ++j) {
            if (0 < i) {
                dp[i][j] += dp[i-1][j];
                if (j+A[i] <= S) dp[i][j+A[i]] += dp[i-1][j];
            }
        }
        res += dp[i][S];
    }
    cout << res << endl;

    return 0;
}