#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 1e18 + 1;

template<int mod>
struct mint {
private:
    long long x;
public:
    mint(long long x = 0) :x(x%mod) {}
    mint(std::string s) {
        long long z = 0;
        REP(i, s.size()) {
            z *= 10;
            z += s[i] - '0';
            z %= mod;
        }
        this->x = z;
    }
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
    friend std::ostream& operator<<(std::ostream& os, const mint& n) {
        return os << n.x;
    }
    bool operator==(const mint a) const {
        return this->x == a.x;
    }
};

int main() {
    string s; cin >> s;
    int n = s.size();
    int d; cin >> d;
    // dp[i][j] : i番目まで見た時の数 j は未満フラグ
    vector<vector<vector<mint<MOD>>>> dp(n+1, vector<vector<mint<MOD>>>(d, vector<mint<MOD>>(2,0)));
    dp[0][0][0] = 1;
    REP(i, n) {
        REP(j, d) {
            dp[i + 1][(s[i] - '0' + j) % d][0] += dp[i][j][0];
            REP(k, 10) {
                if (k < s[i] - '0') dp[i + 1][(k + j) % d][1] += dp[i][j][0];
                dp[i + 1][(k + j) % d][1] += dp[i][j][1];
            }
        }
    }
    cout << dp[n][0][0] + dp[n][0][1] - 1 << endl;
    return 0;
}