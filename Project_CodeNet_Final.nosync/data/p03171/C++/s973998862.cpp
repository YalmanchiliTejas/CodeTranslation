    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    ll dp[3001][3001][2];
    ll arr[3000];
    ll a=0;
    ll b=0;
    ll solve(int s, int e, int a)
    {
        if(s>e)
        {
            return 0;
        }
        else if(dp[s][e][a]!=-1)
        {
            return dp[s][e][a];
        }
        else
        {
            ll b=0;
            b+=max(arr[s]-solve(s+1,e,!a),arr[e]-solve(s,e-1,!a));
            dp[s][e][a]=b;
            return dp[s][e][a];
        }
    }
    int main() {
    int n;
    cin>>n;

    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<2;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    ll ans=solve(0,n-1,1);/*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j][0]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j][1]<<' ';
        }
        cout<<'\n';
    }*/
    cout<<ans<<'\n';
    return 0;
    }
