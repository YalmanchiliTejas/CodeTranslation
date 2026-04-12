#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector <long long> vec (n,0);
    vector <long long> sum(n,0);
    vector <vector <long long>> dp(n,vector<long long>(n,0));
    long long sm=0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sm+=vec[i];
        sum[i]=sm;
    }
    for(int i=1;i<=n;i++){
     for(int j=0;j<=n-i;j++){
         long long sub=(j==0)?0:sum[j-1];
         long long sm=sum[j+i-1]-sub;
         if(i==1)dp[j][j]=vec[j];
         else dp[j][j+i-1]=sm-min(dp[j+1][j+i-1],dp[j][j+i-2]);
     }
    }
    long long oth=sum[n-1]-dp[0][n-1];
    cout<<dp[0][n-1]-oth<<endl;
}