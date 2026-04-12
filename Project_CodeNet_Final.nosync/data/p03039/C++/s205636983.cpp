#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

struct BinomialCoefficient  {
    BinomialCoefficient() {}
    BinomialCoefficient(int n) : fac(n + 2), finv(n + 2), inv(n + 2) {
        initialize(n, false);
    }
    
    void initialize(int n, bool resize = true) {
        if (resize) {
            fac.resize(n + 2);
            finv.resize(n + 2);
            inv.resize(n + 2);
        }
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    
    ll factorial(int n) {
        return fac[n];
    }
    
    ll combination(int n, int r) {
        if ((n < r) || (n < 0) || (r < 0)) return 0;
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
    }
    
    ll permutation(int n, int r) {
        if ((n < r) || (n < 0) || (r < 0)) return 0;
        return fac[n] * finv[n - r] % mod;
    }
    
private:
    int mod = 1e9 + 7;
    vector<ll> fac, finv, inv;
};

struct mint {
    const int mod = 1e9 + 7;
    long long x;
    
    mint (long long x = 0) : x((x % mod + mod) % mod) {
        
    }
    
    mint& operator=(const long long a) {
        x = a % mod;
        return *this;
    }
    
    mint& operator=(const mint a) {
        x = a.x % mod;
        return *this;
    }
    
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    
    mint& operator-=(const mint a) {
        if ((x += (mod - a.x)) >= mod) x -= mod;
        return *this;
    }
    
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    
    mint pow(long long t) const {
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, m, k;
    cin >> n >> m >> k;
    mint ans = 0;
    reps(i, 1, n) {
        mint tmp = i * (n - i);
        tmp *= m * m;
        ans += tmp;
    }
    reps(i, 1, m) {
        mint tmp = i * (m - i);
        tmp *= n * n;
        ans += tmp;
    }
    BinomialCoefficient bc(n * m);
    ans *= bc.combination(n * m - 2, k - 2);
    cout << ans.x << endl;
    return 0;
}
