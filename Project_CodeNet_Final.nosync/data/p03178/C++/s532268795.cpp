#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    
    string s;
    int d;
    cin>>s>>d;
    int n = s.size();
    ll mod = 1e9+7;
    ll dp[n+1][d][2]={};
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<10;k++){
                dp[i+1][(j+k)%d][1] += dp[i][j][1];
                if(s[i]=='0'+k){
                    dp[i+1][(j+k)%d][0] += dp[i][j][0];

                }
                if(s[i]>'0'+k){
                    dp[i+1][(j+k)%d][1] += dp[i][j][0];
                }
                dp[i+1][(j+k)%d][1] %= mod;
                dp[i+1][(j+k)%d][0] %= mod;
            }
        }
    }
    ll ans = dp[n][0][0] + dp[n][0][1];
    ans += mod - 1;
    ans %= mod;
    cout << ans << endl;
}