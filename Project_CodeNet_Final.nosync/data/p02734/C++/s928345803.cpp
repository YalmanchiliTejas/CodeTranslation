#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define rep11(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb(n) push_back(n)
#define mp make_pair
//#define MOD 1000000007
#define INF LONG_LONG_MAX
#define yn(f) cout << (f ? "Yes" : "No") << endl;

#define MOD 998244353


int n,s,a,dp[3001][3001],ans;

signed main() {
    cin >> n >> s;
    dp[0][0] = 1;
    rep1(i,n) {
        cin >> a;
        rep(j,s+1) {
            int d = 0;
            if (j >= a) d = dp[i-1][j-a]%MOD;
            dp[i][j] = (dp[i-1][j] + d)%MOD;
        }
        dp[i][0]++;
        dp[i][0] = dp[i][0]%MOD;
        if (a <= s) {
            //ans += dp[i-1][s-a];
            //rep11(j,i) ans += dp[j][s-a];
        }
        ans = (ans+dp[i][s])%MOD;
    }
    cout << ans%MOD << endl;
}