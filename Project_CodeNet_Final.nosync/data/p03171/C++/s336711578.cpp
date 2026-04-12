#include<bits/stdc++.h>
using namespace std;
long long dp[3001][3001];

long long solve(int i,int j,long long a[])
{
    if(i==j) return a[i];
    if(dp[i][j]!=LLONG_MAX) return dp[i][j];
    long long ans;
    ans=max(a[i]-solve(i+1,j,a),a[j]-solve(i,j-1,a));
    dp[i][j]=ans;
    return ans;
}

int main()
{
    long long n;
    cin>>n;
    long long a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j]=LLONG_MAX;
    cout<<solve(0,n-1,a)<<endl;
    return 0;
}
