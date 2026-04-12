#include<bits/stdc++.h>
using namespace std;
long long dp[3005][3005];
const long long inf=100000000000000000;
int main()
{
int n;
cin>>n;
vector<long long >arr(n);
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
for(int i=0;i<n;i++)
{
    dp[i][i]=arr[i];
}
for(int l=1;l<=n-1;l++)
{

    for(int i=0;i<=n-l;i++)
    {
        long long mx=-inf;
        mx=max(mx,arr[i]-dp[i+1][i+l]);
        mx=max(mx,arr[i+l]-dp[i][i+l-1]);
        dp[i][i+l]=mx;
        //cout<<setw(10)<<dp[i][i+l]<<" ";
    }
}
cout<<dp[0][n-1]<<endl;

return 0;
}
