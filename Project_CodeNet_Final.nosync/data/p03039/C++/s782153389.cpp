#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const int mod = 1000000007;
struct mint {
    ll x;
    mint(ll x = 0) :x((x% mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) {
            x -= mod;
        }
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) {
            x -= mod;
        }
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

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<mint> nck(k-1, 1);
    rep(i, k-2){
        nck[i+1] = nck[i].x * (n*m-2-i);
        nck[i+1] /= (i+1);
    }
    
    ll ans = m * m * nck[k-2].x % mod;
    ll sum = 0;
    rep(i, n-1){
        (sum += (i+1) * (n-1-i)) %= mod;
    }
    (ans *= sum) %= mod;
    ll cnt = n * n * nck[k-2].x % mod;
    sum = 0;
    rep(i, m-1){
        (sum += (i+1) * (m-1-i)) %= mod;
    }
    (cnt *= sum) %= mod;
    cout << (ans + cnt) % mod << endl;
}