#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

template < long long mod >
struct mint {
private:
    long long x;

public:
    mint(long long x = 0) : x((mod + x) % mod) {}
    mint(std::string &s) {
        long long z = 0;
        for (int i = 0; i < s.size(); i++) {
            z *= 10;
            z += s[i] - '0';
            z %= mod;
        }
        this->x = z;
    }
    mint &operator+=(const mint &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint &operator-=(const mint &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint &operator*=(const mint &a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint &operator/=(const mint &a) {
        long long n = mod - 2;
        mint< mod > u = 1, b = a;
        while (n > 0) {
            if (n & 1) {
                u *= b;
            }
            b *= b;
            n >>= 1;
        }
        return *this *= u;
    }
    mint operator+(const mint &a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint &a) const {
        mint res(*this);
        return res *= a;
    }
    mint operator/(const mint &a) const {
        mint res(*this);
        return res /= a;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &n) {
        return os << n.x;
    }
    bool operator==(const mint &a) const {
        return this->x == a.x;
    }
};

int main() {
    constexpr int MOD = 998244353;
    int n, s;
    cin >> n >> s;
    vector< int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // dp[i][j] : i番目を右端とする区間
    vector< vector< mint< MOD > > > dp(n + 1, vector< mint< MOD > >(s + 1, 0));
    vector< mint< MOD > > sum(vector< mint< MOD > >(s + 1, 0));
    dp[0][0] = 1;
    sum[0] = 1;
    mint< MOD > ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1][0] = 1;
        for (int j = s; j >= a[i]; j--) {
            dp[i + 1][j] = sum[j - a[i]];
            sum[j] += dp[i + 1][j];
        }
        sum[0] += 1;
        ans += dp[i + 1][s] * (n - i);
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= s; j++) {
    //         printf("dp[%d][%d] = ", i, j);
    //         cout << dp[i][j] << endl;
    //     }
    // }
    // dump(sum);
    cout << ans << endl;
    return 0;
}

