// In the Name of Allah. Ya Ali!
#include<bits/stdc++.h>
typedef long long ll;
const ll MAX_N = 3000+5;
const ll MOD = 1e9+7;
using namespace std;

ll dp[MAX_N][MAX_N][2];
ll a[MAX_N];
int n;

int main()
{
    cin >> n;
    for(int i = 1;i<=n;++i)
        cin >> a[i];
    for(int i = 1;i<=n;++i)
        dp[1][i][0] = a[i],dp[1][i][1] = -a[i];
    for(int i = 2;i<=n;++i)
    {
        for(int j = 1;j<=n-i+1;++j)
        {
            dp[i][j][0] = max(a[j]+dp[i-1][j+1][1],a[i+j-1]+dp[i-1][j][1]);
            dp[i][j][1] = min(dp[i-1][j+1][0]-a[j],dp[i-1][j][0]-a[i+j-1]);
        }
    }
    cout << dp[n][1][0];
    return 0;
}
