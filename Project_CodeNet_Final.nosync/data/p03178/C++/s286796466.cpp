#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
struct mint {
    int x;
    mint(int x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(int t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const {
        return pow(mod - 2);
    }
    mint& operator/=(const mint a) {
        return *this *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

mint dp[100010][110][2];
string K;
int D;



signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> K;
    cin >> D;
    dp[0][0][0] = 1;
    rep(i, K.length()) {
        rep(j, D) {
            rep(d, 10) {
                int next_d = (j + d) % D;
                dp[i + 1][next_d][1] += dp[i][j][1];
            }
            int num = K[i] - '0';
            int next_d = (j + num) % D;
            dp[i + 1][next_d][0] += dp[i][j][0];
            rep(d, num) {
                next_d = (j + d) % D;
                dp[i + 1][next_d][1] += dp[i][j][0];
            }
        }
    }

    cout << (dp[K.length()][0][0] + dp[K.length()][0][1] - 1).x << endl;

    return 0;
}
