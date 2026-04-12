#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 998244353;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

mint dp[3005][3005][3];

int main(){
    int n, s;
    cin >> n >> s;
    mint ans(0);
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    dp[0][0][0] = mint(1);
    
    rep(i, n) rep(j, s+1) {
        dp[i+1][j][0] += dp[i][j][0];
        dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1];
        dp[i+1][j][2] += dp[i][j][1] + dp[i][j][2];
        if (a[i]+j<=s) {
            dp[i+1][j+a[i]][1] += dp[i][j][0] + dp[i][j][1];
            dp[i+1][j+a[i]][2] += dp[i][j][0] + dp[i][j][1];
        }
    }
    
    
    cout << dp[n][s][2].x << endl;
    return 0;
}
