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
long long dp[3001][3001][2];
long long solve(int idx1,int idx2,bool turn)
{
    if(idx1 > idx2)
        return 0;
    if(dp[idx1][idx2][turn] != -1)
        return dp[idx1][idx2][turn];
    if(turn)
        return dp[idx1][idx2][turn] = max(arr[idx1] + solve(idx1+1,idx2,!turn),arr[idx2] + solve(idx1,idx2-1,!turn));
    else
        return dp[idx1][idx2][turn] = min(-arr[idx1] + solve(idx1+1,idx2,!turn),-arr[idx2] + solve(idx1,idx2-1,!turn));
}
int main()
{
    memset(dp,-1,sizeof dp);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> arr[i];
    cout << solve(1,n,1);
    return 0;
}
