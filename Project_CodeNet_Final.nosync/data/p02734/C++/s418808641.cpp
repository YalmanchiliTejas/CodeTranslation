#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

constexpr i64 MOD = 998244353;

int main(){
    i64 n, s;
    cin >> n >> s;
    vector<i64> v;
    for(int i=0;i<n;++i){
        i64 a;
        cin >> a;
        v.push_back(a);
    }

    vector<vector<i64>> dp(n+1, vector<i64>(s+1));
    for(int i=0;i<=n;++i)dp[i][0] = 1;
    for(int i=0;i<n;++i){
        for(int j=0;j<=s;++j){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD;
            if(j+v[i] > s)continue;
            dp[i+1][j+v[i]] += dp[i][j];
            dp[i+1][j+v[i]] %= MOD;
        }
    }

    i64 ans = 0;
    for(int i=1;i<=n;++i){
        ans += dp[i][s];
        ans %= MOD;
        //cerr << dp[i][s] << " " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}