#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n;
ll a[3005];
ll dp[3005][3005];

ll solve(int i, int j){
    if(i>j)
        return 0;
    
    if(dp [i][j] != -1) 
        return dp[i][j];

    ll op1 = a[i] - solve(i+1,j);
    ll op2 = a[j] - solve(i,j-1);

    return dp[i][j] = max(op1,op2);
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<solve(0,n-1);
}
