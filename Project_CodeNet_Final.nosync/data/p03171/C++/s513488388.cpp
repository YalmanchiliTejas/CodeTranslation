#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[3001][3001];
ll a[3001];
ll fun(int i,int j,bool flag)
{
    if(i == j)
    {
        if(flag)
            return a[i];
        else
            return -a[i];
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(flag)
        return dp[i][j] = max(a[i]+fun(i+1,j,!flag),a[j]+fun(i,j-1,!flag));
    return dp[i][j] = min(-a[i]+fun(i+1,j,!flag),-a[j]+fun(i,j-1,!flag));
}
int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<fun(0,n-1,true)<<endl;
    return 0;
}
