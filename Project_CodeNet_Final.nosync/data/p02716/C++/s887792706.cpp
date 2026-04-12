#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 200005
int n,m;
int ar[mx];
ll dp[mx],dp1[mx];
bool visit[mx][3];



int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);
    }
    ll re;
    if(n%2==0)
    {
        re=-1e18;
        for(int i=0; i<n/2; i++)
        {
            dp[i+1]=dp[i]+ar[i*2];
            dp1[i+1]=dp1[i]+ar[i*2+1];
        }
        for(int i=0; i<=n/2; i++)
        {
            re=max(re,dp[i]+(dp1[n/2]-dp1[i]));
        }
    }
    else
    {
        ll sum=ar[0];
        for(int i=1; i<=n/2; i++)
        {
            dp[i]=ar[i*2]+max(dp[i-1],dp1[i-1]);
            dp1[i]=max(sum,ar[i*2-1]+dp1[i-1]);
            sum+=ar[2*i];
        }
        re=max(dp[n/2],dp1[n/2]);
    }
    printf("%lld\n",re);
    return 0;

}
