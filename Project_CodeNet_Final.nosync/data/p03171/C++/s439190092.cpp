#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7;
int game_strat(int i,int j,vector<int>&A,vector<vector<int>>&dp)
{
    if (i>j)return 0;
    if (dp[i][j]!=-1)return dp[i][j];
    return dp[i][j] = max(A[i]+min(game_strat(i+2,j,A,dp),game_strat(i+1,j-1,A,dp)),A[j]+min(game_strat(i,j-2,A,dp),game_strat(i+1,j-1,A,dp)));
}
int32_t main()
{
    int n;
    cin>>n;
    vector<int>A(n);
    int tot = 0;
    for (int i = 0;i<n;i++){cin>>A[i];tot+=A[i];}
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<2*game_strat(0,n-1,A,dp)-tot<<endl;
    return 0;
}