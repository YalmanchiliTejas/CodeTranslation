#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long
int dp[1000][2][4];
signed main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    dp[0][1][1]=(s[0]>0);
    dp[0][1][0]=0;
    dp[0][0][1]=max(0,s[0]-'1');
    dp[0][0][0]=1;
    FOR(i,1,n) {
        if(s[i]=='0') {
            dp[i][1][0]=dp[i-1][1][0];
            dp[i][1][1]=dp[i-1][1][1];
            dp[i][1][2]=dp[i-1][1][2];
            dp[i][1][3]=dp[i-1][1][3];

            dp[i][0][0]=dp[i-1][0][0];
            dp[i][0][1]=dp[i-1][0][1]+dp[i-1][0][0]*9;
            dp[i][0][2]=dp[i-1][0][2]+dp[i-1][0][1]*9;
            dp[i][0][3]=dp[i-1][0][3]+dp[i-1][0][2]*9;
        } else {
            dp[i][1][0]=0;
            dp[i][1][1]=dp[i-1][1][0];
            dp[i][1][2]=dp[i-1][1][1];
            dp[i][1][3]=dp[i-1][1][2];

            dp[i][0][0]=dp[i-1][0][0]+dp[i-1][1][0];
            dp[i][0][1]=dp[i-1][0][1]+dp[i-1][0][0]*9+dp[i-1][1][1]+dp[i-1][1][0]*(s[i]-'1');
            dp[i][0][2]=dp[i-1][0][2]+dp[i-1][0][1]*9+dp[i-1][1][2]+dp[i-1][1][1]*(s[i]-'1');
            dp[i][0][3]=dp[i-1][0][3]+dp[i-1][0][2]*9+dp[i-1][1][3]+dp[i-1][1][2]*(s[i]-'1');
        }
    }
    cout << dp[n-1][0][k]+dp[n-1][1][k] << endl;
    return 0;
}

