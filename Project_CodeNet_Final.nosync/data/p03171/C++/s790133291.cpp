#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<long long int> v(n);
    for(long long int &x: v){
        cin>>x;
    }
    vector<vector<long long int>> dp(n+1,vector<long long int>(n+1));
    //dp[i][j] denotes the answer for index i to j
     for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                dp[i][j]=v[i];
                continue;
            }
            dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
        }
     }
     cout<<dp[0][n-1];
}
