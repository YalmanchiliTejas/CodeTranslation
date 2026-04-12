#include<bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
        int n;
        cin>>n;
        
        vector<ll>piles(n);
        for(int i=0;i<n;i++) cin>>piles[i];
        if(n==1) {cout<<piles[0]; return 0;}
        vector<vector<ll> >dp(n,vector<ll>(n));
        
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<n;i++)
            {
                int j=i+len-1;
                if(j>=n) continue;
                if(len==2)
                    dp[i][j]=abs(piles[i]-piles[j]);
                else
                {
                    dp[i][j]=max(piles[j]-dp[i][j-1],piles[i]-dp[i+1][j]);
                }
                
            }
        }
        cout<< dp[0][n-1];
        
        return 0;
}