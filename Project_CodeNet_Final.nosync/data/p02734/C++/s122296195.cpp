#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int N = 3007, MOD = 998244353;

struct mint {
    int val;
 
    mint(int v = 0) {
        val = v % MOD;
        if(val < 0) val += MOD;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mint& operator+=(const mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mint& operator-=(const mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    mint& operator*=(const mint &other) {
        val = ((uint64_t) val*other.val)%MOD;
        return *this;
    }
 
    mint& operator/=(const mint &other) {
        return *this *= other.inv();
    }
 
    friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
    friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
    friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
    friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
 
    mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mint operator++(int32_t) { mint before = *this; ++*this; return before; }
    mint operator--(int32_t) { mint before = *this; --*this; return before; }
 
    mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mint &other) const { return val == other.val; }
    bool operator!=(const mint &other) const { return val != other.val; }
 
    mint inv() const {
        return mod_inv(val);
    }
 
    mint pow(int p) const {
        mint a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mint &m) {
        return stream << m.val;
    }
};

int n, s, a[N];
mint dp[N][N][3];

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dp[0][0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= s; ++j) {
            //don't add me
            dp[i+1][j][0] += dp[i][j][0];
            dp[i+1][j][1] += dp[i][j][0];
            dp[i+1][j][2] += dp[i][j][0];
            
            dp[i+1][j][1] += dp[i][j][1];
            dp[i+1][j][2] += dp[i][j][1];
            
            dp[i+1][j][2] += dp[i][j][2];

            //add me
            int nxt = j+a[i];
            if(nxt <= s) {
                dp[i+1][nxt][1] += dp[i][j][0];
                dp[i+1][nxt][2] += dp[i][j][0];

                dp[i+1][nxt][1] += dp[i][j][1];
                dp[i+1][nxt][2] += dp[i][j][1];
            }
        }
    }

    cout << dp[n][s][2] << '\n';
    
    return 0;
}
