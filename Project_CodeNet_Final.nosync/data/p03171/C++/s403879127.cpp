#include<bits/stdc++.h>
using namespace std;

typedef int in;
#define int long long
int MAX=1e9;
int MAXEST=1e18;
int MOD=1e9+7;

int n;
int a[3005];
int dp[3005][3005];

int f(int s,int e,bool t)
{
    if(s>e) return 0;
    int &ret=dp[s][e];
    if(ret!=-1)
        return ret;
    if(t)
        return ret=min(f(s+1,e,0)-a[s],f(s,e-1,0)-a[e]);
    return ret=max(f(s+1,e,1)+a[s],f(s,e-1,1)+a[e]);
}

in main()
{
    int tc=1;
//    cin>>tc;
    while(tc--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        memset(dp,-1,sizeof dp);
        cout<<f(0,n-1,0)<<endl;
    }
    return 0;
}
