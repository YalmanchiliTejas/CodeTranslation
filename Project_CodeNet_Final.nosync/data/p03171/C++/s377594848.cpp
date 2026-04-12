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
        vector<vector<long long int >>dp(n,vector<long long int >(n,0));
        for(long long int  l=0;l<=n-1;l++){
            for(long long int  i=0;i<n-l;i++){
                long long int  j=i+l;
                if(i==j) dp[i][j]=p[i];
                else {
                    dp[i][j]=max(p[i]-dp[i+1][j],(-1)*dp[i][j-1]+p[j]);
                }
            }
        }
    cout<<dp[0][n-1];
    return 0;

}