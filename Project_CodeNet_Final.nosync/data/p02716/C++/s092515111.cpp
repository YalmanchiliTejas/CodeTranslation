#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int arr[200005];
long long int INF = 1e18 + 7;

long long int cal(int idx)
{
    long long int sum = 0;
    for(int i=idx;i<n;i+=2)
        sum += arr[i];
    return sum;
}


long long int dp[200005][2][2][2];

long long int kil_even(int idx, int ls, int ds, int ts)
{
    if(idx == n)
        return 0;
        
    if(dp[idx][ls][ds][ts] != -1)
        return dp[idx][ls][ds][ts];
    dp[idx][ls][ds][ts] = -INF;
    if(!ls)
    {
        if(!ds)
            dp[idx][ls][ds][ts] = max(dp[idx][ls][ds][ts], kil_even(idx+1, 0, 1, ts));
        dp[idx][ls][ds][ts] = max(dp[idx][ls][ds][ts], kil_even(idx+1, 1, ds, ts) + arr[idx]);
    }
    else
    {
        dp[idx][ls][ds][ts] = max(dp[idx][ls][ds][ts], kil_even(idx+1, 0, ds, ts));
    }
    return dp[idx][ls][ds][ts];
}

long long int kil(int idx, int ls, int ds, int ts)
{
    if(idx == n)
    {
        if(ds == 1)
            return 0;
        return -INF;
    }
    if(dp[idx][ls][ds][ts] != -1)
        return dp[idx][ls][ds][ts];
    dp[idx][ls][ds][ts] = -INF;
    if(!ls)
    {
        if(!ds)
            dp[idx][ls][ds][ts] = max(dp[idx][ls][ds][ts], kil(idx+1, 0, 1, 0));
        if(ds == 1 && ts == 0)
            dp[idx][ls][ds][ts] = max(dp[idx][ls][ds][ts], kil(idx+1, 0, 1, 1));
        dp[idx][ls][ds][ts] = max(dp[idx][ls][ds][ts], kil(idx+1, 1, ds, ts) + arr[idx]);
    }
    else
    {
        dp[idx][ls][ds][ts] = max(dp[idx][ls][ds][ts], kil(idx+1, 0, ds, ts));
    }
    return dp[idx][ls][ds][ts];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    memset(dp, -1, sizeof dp);

    if(!(n&1))
        cout<<max(cal(1), kil_even(1 ,1, 0, 0) + arr[0])<<endl;
    else
        cout<<kil(0, 0, 0, 0)<<endl;

    return 0;
}
