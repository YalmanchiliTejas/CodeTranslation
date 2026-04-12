#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
ll dp[3001][3001];
int n;

ll solve(int i, int j, int A[]){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll op1=A[i]+min(solve(i+2,j,A),solve(i+1,j-1,A));
    ll op2=A[j]+min(solve(i,j-2,A),solve(i+1,j-1,A));
    return dp[i][j]=max(op1,op2);
    
}

int main(){
    cin>>n;
    int A[n];
     ll sum=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){ cin>>A[i]; sum+=A[i]; }
    ll x=solve(0,n-1, A);
    ll y=sum-x;
    cout<<x-y;
}//