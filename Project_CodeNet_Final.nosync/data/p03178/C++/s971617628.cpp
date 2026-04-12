#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;

int main(){
    string k;
    int d;
    cin >> k >> d;

    int n = k.length();
    vector<vector<long long int>> dp(n+1, vector<long long int>(d));// dp[i][j] = #(i digits, dsum % d == j)
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<d; j++){
            for(int l=0; l<10; l++){// top digit
                dp[i+1][j] += dp[i][((j-l)%d+d)%d];
                dp[i+1][j] %= MOD;
            }
        }
    }
    /*
    for(int i=0; i<=n; i++){
        for(int j=0; j<d; j++){
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }
    */

    long long int ans = 0;
    int total = 0;
    for(int i=0; i<n; i++){
        int cd = k[i] - '0';// 0 ~ 9
        for(int j=0; j<cd; j++){
            ans += dp[n-1-i][(-(total+j)%d+d)%d];
            //cout << "dp[" << n-1-i << "][" << ((-(total+j)%d+d)%d) << "] = " << dp[n-1-i][(-(total+j)%d+d)%d] << endl;
            ans %= MOD;
        }
        total += cd;
    }
    ans -= 1;// since 0 is counted
    if(total % d == 0) ans += 1;
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
    return 0;
}