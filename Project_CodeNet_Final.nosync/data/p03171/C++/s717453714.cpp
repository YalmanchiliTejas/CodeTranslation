#include<bits/stdc++.h>
using namespace std;

long int dp[3001][3001];


long long int func(int start,int end,int n,vector<long long int> &v)
{
    if(start>end)
    {
        return 0;
    }
    
    int turn=n-(end-start+1);
    
    if(turn%2==0)
    {
        turn=1;
    }
    else
    {
        turn=0;
    }
    
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
        
    if(turn==1)
    {
        dp[start][end]=max(v[start]+func(start+1,end,n,v),v[end]+func(start,end-1,n,v));
        return dp[start][end];
    }
    else if(turn==0)
    {
        dp[start][end]=min(func(start+1,end,n,v)-v[start],func(start,end-1,n,v)-v[end]);
        return dp[start][end];
    }
    
}

int main()
{
    
        int n;
        cin>>n;
        vector<long long int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        
        int start=0;
        int end=n-1;
        
        memset(dp,-1,sizeof(dp));
        cout<<func(start,end,n,v);
        
        
    return 0;
}