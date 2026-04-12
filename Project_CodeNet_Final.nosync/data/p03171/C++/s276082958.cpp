#include<bits/stdc++.h>
using namespace std;
long long int dfs(int l, int r, vector<long long int>& v, vector<vector<long long int>>& dp)
{
    if(l==r)
        return v[l];
    if(dp[l][r]!=INT_MAX)
        return dp[l][r];
    return dp[l][r] = max(v[l]-dfs(l+1, r, v, dp), v[r]-dfs(l, r-1, v, dp));
}
int main()
{
    int n;
    cin>>n;
    vector<long long int> v(n, 0);
    vector<vector<long long int>> dp(n, vector<long long int>(n, INT_MAX));
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<dfs(0, n-1, v, dp);
    return 0;
}
 