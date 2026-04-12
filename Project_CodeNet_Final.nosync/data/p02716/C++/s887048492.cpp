//
//  main.cpp
//  F
//
//  Created by 曾憲揚 on 2020/8/21.
//  Copyright © 2020 曾憲揚. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];
long long dp[maxn];
long long sum[maxn];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof(dp));
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    
    for(int i=1; i<=n; i+=2){
        sum[i] = i>2? sum[i-2]+a[i] : a[i];
    }
    
    dp[0] = dp[1] = 0;
    for(int i=2; i<=n; i++){
        if(i&1) dp[i] = max(dp[i-1], dp[i-2]+a[i]);
        else    dp[i] = max(sum[i-1], dp[i-2]+a[i]);
    }
    cout<<dp[n]<<endl;
    return 0;
}
