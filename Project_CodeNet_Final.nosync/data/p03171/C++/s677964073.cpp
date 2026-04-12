//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    ll arr[N];
    ll sum = 0;
    
    for(ll i=0;i<N;++i)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    
    ll dp[N][N][2];
    memset(dp,0,sizeof(dp));
    
    for(ll diff = 0;diff<N;++diff)
    {
        for(ll i=0;i<N;++i)
        {
            ll j = i + diff;
            
            if(j >= N)
                continue;
            
            if(diff == 0) //base case
            {
                dp[i][j][0] = arr[i];
                dp[i][j][1] = 0;
                continue;
            }
            
            dp[i][j][0] = max(dp[i + 1][j][1] + arr[i],dp[i][j - 1][1] + arr[j]);
            dp[i][j][1] = min(dp[i + 1][j][0],dp[i][j - 1][0]);
        }
    }

    
    cout<<(2LL*dp[0][N - 1][0] - sum)<<endl;
}