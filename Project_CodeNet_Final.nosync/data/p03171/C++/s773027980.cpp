#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>dp;
ll f(vector<ll>&A,int i,int j)
{
    if(i>j)
        return 0;
    if(i==j)return A[i];
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=max(A[i]+min(f(A,i+1,j-1),f(A,i+2,j)),A[j]+min(f(A,i+1,j-1),f(A,i,j-2)));
    return dp[i][j];
}
int main()
{
    int n;
    cin>>n;
    vector<ll>A(n);
    long long total=0;
    for(ll &i:A){
        cin>>i;
        total+=i;
    }
    dp.resize(n+1,vector<ll>(n+1,-1));
    cout<<f(A,0,n-1)+f(A,0,n-1)-total;
}