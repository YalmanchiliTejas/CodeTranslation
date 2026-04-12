//
//  main.cpp
//  F
//
//  Created by 曾憲揚 on 2020/8/12.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
const int MOD = 998244353;
int a[maxn];
long long dp[maxn][maxn];

int main(int argc, const char * argv[]) {
    memset(dp, 0, sizeof(dp));
    
    int n, s; cin >> n >> s;
    for(int i=1; i<=n; i++) cin >> a[i];
    
    
    long long ans = 0;
    //dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        
            for(int j=0; j<=s; j++){
                dp[i][j] = dp[i-1][j];
            }
            dp[i][a[i]] += i;
            for(int j=1; j+a[i]<=s; j++){
                dp[i][j+a[i]] += dp[i-1][j];
                dp[i][j+a[i]] %= MOD;
            }
            ans += dp[i][s];
            ans %= MOD;
        
    }
    
    /*for(int i=0; i<=n; i++){
        for(int j=0; j<=s; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][s] << endl;*/
    cout << ans << endl;
    return 0;
}
