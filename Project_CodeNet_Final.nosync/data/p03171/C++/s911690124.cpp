#include <bits/stdc++.h>
using namespace std;
long long dp[3001][3001];
int a[3001],n;
long long fun(int s,int e,bool turn)
{
    if(s>e) return 0;
    long long &ret=dp[s][e];
    if(~ret)
        return ret;
    if(!turn)
    {
        return ret=max(a[s]+fun(s+1,e,!turn),a[e]+fun(s,e-1,!turn));
    }
    return ret=min(-a[s]+fun(s+1,e,!turn),-a[e]+fun(s,e-1,!turn));
}
int main()
{
    memset(dp,-1,sizeof dp);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
 cout<<fun(0,n-1,0)<<endl;
}
