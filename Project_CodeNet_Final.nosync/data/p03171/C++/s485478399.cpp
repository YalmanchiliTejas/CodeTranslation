#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
int main(){
    long long n,A[3000],dp[3001][3001]={0};
    cin>>n;
    rep(i,n) cin>>A[i];
    rep(i,n)rep(j,n-i) dp[i+1][j]=max(A[i+j]-dp[i][j],A[j]-dp[i][j+1]);
    cout<<dp[n][0];
}