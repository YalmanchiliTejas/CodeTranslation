#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define pb push_back
#define f first
#define sec second

lli dp[3001][3001], arr[3001];

lli solve(lli start, lli end)
{
    lli a,b,i,j;
    if(start>end)
    {
        return 0;
    }

    if(dp[start][end] != 0)
    {
        return dp[start][end];
    }
    a = arr[start] + min(solve(start+1,end-1) ,solve(start+2,end));
    b = arr[end] + min(solve(start,end-2), solve(start+1,end-1) );

    dp[start][end] = max(a,b);

    return (dp[start][end]);
}

main()
{
    lli n,i,a,t,b,c,j,k,x,y,sum=0;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j] = 0;
        }
        dp[i][i] = arr[i];
    }
    for(i=0;i<n-1;i++)
    {
        dp[i][i+1] = max(arr[i],arr[i+1]);
    }

    a = solve(0,n-1);
    sum -= a;
    a -= sum;

    cout<<a;
}
