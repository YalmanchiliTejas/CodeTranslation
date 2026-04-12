#include<bits/stdc++.h>
using namespace std;

long long int n;
vector<long long int> v;
long long int dp[3005][3005];

long long int solve(long long int l,long long int r)
{
    if(l==r)
        return dp[l][r]=v[l];
    if(dp[l][r]!=-1)
        return dp[l][r];

    dp[l][r]=max(v[l]-solve(l+1,r),v[r]-solve(l,r-1));
    return dp[l][r];
}

int main()
{
    cin>>n;

    for(long long int i=0;i<n;i++)
    {
        long long int y;
        cin>>y;
        v.push_back(y);
    }

    for(long long int i=0;i<3005;i++)
        for(long long int j=0;j<3005;j++)
            dp[i][j]=-1;

    cout<<solve(0,n-1);
}
