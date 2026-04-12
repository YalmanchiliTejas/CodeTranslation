#include<bits/stdc++.h>
// unbounded knapsack..
using namespace std;
using ll=long long ;
int  main(){
        long long int  n;
        cin>>n;
        vector<long long int >p(n,0);
        for(long long int  i=0;i<n;i++){
            cin>>p[i];
        }
        vector<vector<pair<ll,ll>>>dp(n,vector<pair<ll,ll> >(n,{0,0}));
        for(long long int  l=0;l<=n-1;l++){
            for(long long int  i=0;i<n-l;i++){
                long long int  j=i+l;
                if(i==j) dp[i][j]={p[i],p[i]};
                else {
                    dp[i][j].first=max(p[i]+dp[i+1][j].second-dp[i+1][j].first, p[j]+dp[i][j-1].second-dp[i][j-1].first);
                    dp[i][j].second=dp[i+1][j].second+p[i];
                }
            }
        }
    cout<<2*dp[0][n-1].first-dp[0][n-1].second;
    return 0;
}
// x-y    y=sum-x  x-sum+x 2x-sum