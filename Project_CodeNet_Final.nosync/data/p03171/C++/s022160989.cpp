#include<bits/stdc++.h>
using namespace std;
    int n;
    int m[3001];
    long long dp[3001][3001][2];
    long long solve(int start,int end,int k)
    {
        //System.out.println(start+" "+end+" "+k);
        if(start>end)
            return 0;
        if(dp[start][end][k]!=-1)
            return dp[start][end][k];
        if(k==0)
        {
            dp[start][end][k]=max(solve(start+1,end,1)+m[start],solve(start,end-1,1)+m[end]);
        }
        else
        {
            dp[start][end][k]=min(solve(start+1,end,0)-m[start],solve(start,end-1,0)-m[end]);
        }
        return dp[start][end][k];
    }
    int main()
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        cin>>m[i];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=1;k++)
                    dp[i][j][k]=-1;
            }
        }
        cout<<solve(1,n,0)<<endl;
        return 0;
    }