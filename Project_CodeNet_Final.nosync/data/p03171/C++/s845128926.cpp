#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3001][3001];

ll go(ll arr[],ll i,ll j)
{
    if(i>j)
        return 0;
        
    if(i==j)
        return arr[i];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    ll ans1 = arr[i] + min(go(arr,i+2,j),go(arr,i+1,j-1));
    ll ans2 = arr[j] + min(go(arr,i,j-2),go(arr,i+1,j-1));
    
    dp[i][j] = max(ans1,ans2);
    return dp[i][j];
}

int main()
{
    int n;
    cin >> n;

    ll arr[n+1];
    ll sum = 0;
    
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    memset(dp,-1,sizeof(dp));
    ll x = go(arr,1,n);
    ll y = sum - x;
    
    cout << x - y << endl;
    return 0;
    
}