#include<iostream>
using namespace std;

int n;
int v[3005];
long long dp[3005][3005];

int main(){

    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];

    for(int i=1;i<=n;i++)
        dp[i][i]=v[i];

    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++)
            dp[i][j]=max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);

    cout<<dp[1][n];

}
