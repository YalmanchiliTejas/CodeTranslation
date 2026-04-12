#include<bits/stdc++.h>
using namespace std;
int n,a[100002];
long long dp[3002][3002],s=0;
long long solve(int i,int j){
    if(i>j)
        return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long ans =-1;
    ans=max(a[i]+min(solve(i+2,j),solve(i+1,j-1)),a[j]+min(solve(i+1,j-1),solve(i,j-2)));
    dp[i][j]=ans;
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<2*solve(1,n)-s;

}
