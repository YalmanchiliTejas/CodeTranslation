#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

ll arr[3001];
ll dp[3001][3001];

ll findMax(ll s,ll e){
    if(s==e){
        return arr[s];
    }
    if(s>e){
        return 0;
    }
    if(dp[s][e]!=-1){
        return dp[s][e];
    }
    
    
    ll ans1 = arr[s] + min(findMax(s+1,e-1),findMax(s+2,e));
    ll ans2 = arr[e] + min(findMax(s+1,e-1),findMax(s,e-2));
    dp[s][e] = max(ans1,ans2);
    return dp[s][e];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    
    ll num;
    cin>>num;
    for(ll i=0;i<num;i++){
        cin>>arr[i];
    }
    
    ll ans1 = findMax(0,num-1);
    
    ll total = 0;
    for(ll i=0;i<num;i++){
        total += arr[i];
    }
    ll ans2 = total-ans1;
    cout<<ans1 - ans2;
    return 0;
}
