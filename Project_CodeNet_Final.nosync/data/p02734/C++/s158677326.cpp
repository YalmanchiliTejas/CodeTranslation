#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 998244353
#define endl "\n"
#define int long long
typedef long long ll;
using namespace std;

const int N = 3333;
int a[N], dp[N][N][3];
int n, s;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    rep(i, 1, n) {
        cin >> a[i];
    }
    dp[0][0][0] = 1;
    rep(r, 1, n) {
        rep(cs, 0, s) {
            int ps = cs - a[r];
            dp[r][cs][0] = dp[r - 1][cs][0];
            dp[r][cs][1] = dp[r - 1][cs][0] + dp[r - 1][cs][1];
            dp[r][cs][2] = dp[r - 1][cs][0] + dp[r - 1][cs][1] + dp[r - 1][cs][2];
            if(ps >= 0) {
                dp[r][cs][1] += dp[r - 1][ps][0] + dp[r - 1][ps][1];
                dp[r][cs][2] += dp[r - 1][ps][0] + dp[r - 1][ps][1];
            }
            dp[r][cs][0] %= MOD;
            dp[r][cs][1] %= MOD;
            dp[r][cs][2] %= MOD;
        }
    }
    cout << dp[n][s][2] << endl;
    return 0;
}
