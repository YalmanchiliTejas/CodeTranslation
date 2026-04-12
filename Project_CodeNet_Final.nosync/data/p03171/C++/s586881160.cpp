#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3005][3005];
signed main()
{
   ll n, x = 0, y = 0;
   cin >> n;
   ll arr[n+10] = {0};
   for(ll i = 0; i < n; i++)cin >> arr[i+1];
   for(int win = 1; win <= n; win++){
       for(int l = 1, r = win; r <= n; r++, l++){
           if((n-win)%2 == 0){
               dp[l][r] = max(dp[l+1][r] + arr[l], dp[l][r-1] + arr[r]);
           }
           else {
               dp[l][r] = min(dp[l+1][r] - arr[l], dp[l][r-1] - arr[r]);
           }
       }
   }
    cout << dp[1][n];
}