#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    vector<vector<vector<ll>>> dp(s.size()+1, vector<vector<ll>>(k+1, vector<ll>(2, 0)));
    dp[0][0][1] = 1;
    REP(i, s.size()){
        ll now = s[i-1] - '0';
        rep(j, k+1){
            dp[i][j][0] += dp[i-1][j][0];
            if(now == 0)dp[i][j][1] = dp[i-1][j][1];
            else{
                dp[i][j][0] += dp[i-1][j][1];
                if(j != 0){
                    dp[i][j][0] += dp[i-1][j-1][1] * (now-1);
                    dp[i][j][1] += dp[i-1][j-1][1];
                }
            }
            if(j != 0)dp[i][j][0] += dp[i-1][j-1][0] * 9;
        }
    }
    cout << dp[s.size()][k][0] + dp[s.size()][k][1] << endl;
}
