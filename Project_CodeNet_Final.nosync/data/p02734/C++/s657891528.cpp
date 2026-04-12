#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 998244353;

template <int MOD = 1000000007>
struct Mint{
    int x;

    Mint() : x(0) {}
    Mint(long long t){
        x = t % MOD;
        if(x < 0) x += MOD;
    }
    
    Mint pow(int n){
        Mint res(1), t(x);
        while(n > 0){
            if(n & 1) res *= t;
            t *= t;
            n >>= 1;
        }
        return res;
    }

    Mint inv() const {
        int a = x, b = MOD, u = 1, v = 0, t;
        while(b > 0){
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return Mint(u);
    }

    Mint & operator += (Mint a){
        x += a.x;
        if(x >= MOD) x -= MOD;
        return *this;
    }
    
    Mint & operator -= (Mint a){
        x += MOD - a.x;
        if(x >= MOD) x -= MOD;
        return *this;
    }

    Mint & operator *= (Mint a){
        x = int(1LL * x * a.x % MOD);
        return *this;
    }

    Mint & operator /= (Mint a){
        return (*this) *= a.inv();
    }

    Mint operator + (Mint a) const { return Mint(x) += a; }
    Mint operator - (Mint a) const { return Mint(x) -= a; }
    Mint operator * (Mint a) const { return Mint(x) *= a; }
    Mint operator / (Mint a) const { return Mint(x) /= a; }

    Mint operator - () const{ return Mint(-x); }

    bool operator == (const Mint a){ return x == a.x; }
    bool operator != (const Mint a){ return x != a.x; }
    bool operator < (const Mint a){ return x < a.x; }

    friend ostream & operator << (ostream & os, const Mint &a){
        return os << a.x;
    }

    friend istream & operator >> (istream & is, Mint &a){
        int t;
        is >> t;
        a = Mint<MOD>(t);
        return (is);
    }
};

signed main() {
    int n, s;
    cin >> n >> s;
    int a[n];
    rep(i,n){
        cin >> a[i];
    }
    Mint<MOD> dp[n + 1][s + 1][3];
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s;j++){
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
            dp[i + 1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            if (j - a[i] < 0) continue;
            dp[i + 1][j][1] += dp[i][j - a[i]][0] + dp[i][j - a[i]][1];
            dp[i + 1][j][2] += dp[i][j - a[i]][0] + dp[i][j - a[i]][1];
        }
    }
    cout << dp[n][s][2] << endl;
    return 0;
}