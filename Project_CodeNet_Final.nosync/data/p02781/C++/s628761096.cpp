#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    // dp[i][j][exact/smaller] := 上からi桁目を見たときのj個0でない数字が含まれている0より大きい数の数
    vector<VVL> dp(n+1, VVL(10, VL(2,0)));
    dp[0][0][0] = 1;
    rep(i, 1, n+1){
        // smaller -> smaller
        rep(j, 0, k+1){
            dp[i][j+1][1] += 9*dp[i-1][j][1];
            dp[i][j][1] += dp[i-1][j][1];
        }
        // exact -> smaller
        rep(j, 0, k+1){
            if(s[i-1] != '0'){
                dp[i][j+1][1] += (s[i-1]-'0'-1) * dp[i-1][j][0];
                dp[i][j][1] += dp[i-1][j][0];
            }
        }
        // exact -> exact
        rep(j, 0, k+1){
            if(s[i-1] == '0') dp[i][j][0] = dp[i-1][j][0];
            else dp[i][j+1][0] = dp[i-1][j][0];
        }
    }
    cout << dp[n][k][0] + dp[n][k][1] << endl;
    return 0;
}