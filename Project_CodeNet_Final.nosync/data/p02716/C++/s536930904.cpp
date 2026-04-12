#include<bits/stdc++.h>
using  namespace std;
#define endl '\n' 
#define ll long long
#define AC ios::sync_with_stdio(false);cin.tie(0);
const ll N=2e5;
ll dp[N][2];
ll arr[N];

int main()
{
    AC
    ll n;
    cin >> n;
    for (int i= 1; i<=n; i++) cin>> arr[i];
    dp[2][0]=arr[1];dp[2][1]=arr[2];
    for (int i= 3; i<=n; i++)
    {
        if (i&1)
        {
            dp[i][1]=max({dp[i-2][1],dp[i-2][0],dp[i-3][1],dp[i-3][0]})+ arr[i];
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        }
        else 
        {
            dp[i][1]=max(dp[i-2][1],dp[i-2][0])+ arr[i];
            dp[i][0]=arr[i-1]+dp[i-2][0];
        }
    }
    cout<<max(dp[n][0],dp[n][1])<<'\n';
}