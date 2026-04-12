#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    /* code */
int n;
cin>>n;
long long int a[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
vector<vector<pair<long long int,long long int>>> dp(n,vector<pair<long long int,long long int>>(n,{0,0}));
for(int i=0;i<n;i++)
{
    dp[i][i].first=a[i];
    dp[i][i].second=0;
}
for(int i=0;i<n-1;i++)
{
    dp[i][i+1].first=max(a[i],a[i+1]);
    dp[i][i+1].second=min(a[i],a[i+1]);
}
for(int gap=2;gap<n;gap++)
{
    for(int i=0,j=gap;j<n;j++,i++)
    {
        if(a[i]+dp[i+1][j].second>a[j]+dp[i][j-1].second)
        {
            dp[i][j].first=a[i]+dp[i+1][j].second;
        }
        else
        {
            dp[i][j].first=a[j]+dp[i][j-1].second;
        }
        dp[i][j].second=min(dp[i+1][j].first,dp[i][j-1].first);
    }
}
cout<<dp[0][n-1].first-dp[0][n-1].second<<endl;
return 0;
}