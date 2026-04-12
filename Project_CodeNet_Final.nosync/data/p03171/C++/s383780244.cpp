#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back
#define pii pair<long long,long long>
#define endl '\n'
#define N 300001
vector<vector<int>>dp;
int func(vector<int>&v, int i, int j)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    dp[i][j]=0;
    return dp[i][j]=max(v[i]+min(func(v,i+2,j),func(v,i+1,j-1)),v[j]+min(func(v,i,j-2),func(v,i+1,j-1)));
}
void solve()
{
    int n; cin>>n;
    vector<int> v(n);int sum=0;
    for(int i=0;i<n;i++)
    cin>>v[i],sum+=v[i];
    dp.resize(n+1,vector<int>(n+1,-1));
    int comp=func(v,0,n-1);
    cout<<comp-(sum-comp);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test; test=1;
    while(test--)
    {
        solve();
    }
    return 0;
}