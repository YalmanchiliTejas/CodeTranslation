#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

constexpr int M = 13333;
ll dp[M][2][111];

int main(int argc, char const *argv[]) {
    int d; string s; cin>>s>>d;
    int n = s.length();
    memset(dp,0,sizeof(dp));

    dp[0][0][0] = 1ll;

    rep(i,n) {
        int D = (int)(s[i]-'0');
        rep(j,2) {
            for (int x = 0; x <= (j?9:D); ++x) {
                rep(k,d) {
                    dp[i+1][j||(x < D)][(k+x)%d] = (dp[i+1][j||(x < D)][(k+x)%d]+dp[i][j][k])%MOD;
                }
            }
        }
    }


    cout << max(((dp[n][0][0]%MOD+dp[n][1][0]%MOD+MOD)-1ll)%MOD,0ll) << endl;

    return 0;
}