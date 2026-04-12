#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[3004],dp[3004][3004][2];
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    IOS;
    int n;  cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i][i][0] = a[i]; 
        dp[i][i][1] = -a[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(j+i <= n)
            {
                dp[j][j+i][0] = max(dp[j+1][j+i][1] + a[j] , dp[j][j+i-1][1] + a[j+i]);
                dp[j][j+i][1] = min(dp[j+1][j+i][0] - a[j] , dp[j][j+i-1][0] - a[j+i]);
            }
        }
    }
   /* for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<dp[i][j][0]<<" ";
        }
        cout<<endl;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<dp[i][j][1]<<" ";
        }
        cout<<endl;
    }*/
    ll ans = 0;
    ans = dp[1][n][0];
     cout<<ans<<endl;
     return 0;
}
