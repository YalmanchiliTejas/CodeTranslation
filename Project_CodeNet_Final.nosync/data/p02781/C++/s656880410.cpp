#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,double> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

ll dp[110][2][5];

int main() {
    string s;cin>>s;
    int k;cin>>k;
    int n = s.size();
    dp[0][0][0] = 1;
    rep(i,n) {
        int num = s[i] - '0';
        rep(j,5) {
            dp[i+1][1][min(4,j+1)] += 9*dp[i][1][j];
            dp[i+1][1][j] += dp[i][1][j];
        }
        if(num==0) {
            rep(j,5) dp[i+1][0][j] += dp[i][0][j];
        } else {
            rep(j,5) dp[i+1][0][min(4,j+1)] += dp[i][0][j];
        }
        // if(num==1) {
        //     if(i==0) continue;
        //     rep(j,5) dp[i+1][1][j] += dp[i][0][j];
        // } else if (num >= 2) {
        //     rep(k,num) {
        //         if(i==0) 
        //     }
        //     rep(j,5) dp[i+1][1][min(4,j+1)] += dp[i][0][j];
        // }

        if(num>=1) {
            rep(j,num) {
                // if(i==0&&j==0) continue;
                if(j==0) rep(p,5) dp[i+1][1][p] += dp[i][0][p];
                else rep(p,5) dp[i+1][1][min(4,p+1)] += dp[i][0][p];
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k] << endl;
}