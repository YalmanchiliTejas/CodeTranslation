#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int,int> ,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
long long MOD = 1e9+7;
pair<int,int> dx[4] = {{1,0},{-1,0},{0,1},{0,-1}};
long long fastpow(long long x,long long k)
{
    if(!k)
        return 1;
    if(k & 1)
        return ((x * fastpow(x,k-1) % MOD) % MOD) % MOD;
    long long ans = fastpow(x,k/2);
    ans %= MOD;
    ans *= ans;
    ans %= MOD;
    return ans;
}
long long sumF(long long x)
{
    int s = 0;
    while(x)
        s += x%10,x /= 10;
    return s;
}
long long arr[3005];
long long arr2[3005];
long long dp[2][3001];
int n;
int main()
{
   // memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];
    for(int i = n;i >= 1;i--)
        arr2[i] = arr[n-i+1];
    //cout << solve(n,n,1);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(i+j <= n)
                continue;
            dp[i%2][j] = 0;
            if((i+j)%2 == (n+n)%2)
                dp[i%2][j] = max(arr2[i] + dp[(i-1)%2][j],arr[j] + dp[i%2][(j-1)]);
            else
                dp[i%2][j] = min(-arr2[i] + dp[(i-1)%2][j],-arr[j] + dp[i%2][(j-1)]);
        }
    }
    cout << dp[n%2][n];
    return 0;
}
