#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

struct mint {
    const int mod = 998244353;
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
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<mint> dp(s + 1, 0);
    mint ans = 0;
    rep(i, n) {
        dp[0] += 1;
        rreps(j, a[i], s + 1) {
            if (j == s) ans += dp[j - a[i]] * (n - 1 - i);
            dp[j] += dp[j - a[i]];
        }
    }
    ans += dp[s];
    cout << ans.x << endl;
    return 0;
}
