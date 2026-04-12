#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j;
    cin>>n;
    vector<int>arr(n);
    for(i=0;i<n;i++) cin>>arr[i];
    vector<pair<long long,long long> >dp(n);
    dp[n-1].first=arr[n-1];
    dp[n-1].second=-arr[n-1];
    for(i=n-2;i>=0;i--)
    {
        dp[i].first=arr[i];
        dp[i].second=-arr[i];
        for(j=i+1;j<n;j++)
        {
            long long f=dp[j].first;
            long long s=dp[j].second;
            dp[j].first=max(arr[i]+s,arr[j]+dp[j-1].second);
            dp[j].second=min(-arr[i]+f,-arr[j]+dp[j-1].first);
        }
    }
    cout<<dp[n-1].first<<endl;
}
