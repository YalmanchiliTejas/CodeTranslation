#include <bits/stdc++.h>
using namespace std;
long long int dp[3010][3010];
int main(){
    long long int n,l,r,i,a[3010];
    cin>>n;
    for(i=1;i<n+1;i++){
        cin>>a[i];
    }
    for(l=n;l>0;l--){
        for(r=1;r<n+1;r++){
            if(l>r) dp[l][r]=0;
            else if(l==r) dp[l][r]=a[l];
            else dp[l][r]=max(a[l]-dp[l+1][r] , a[r]-dp[l][r-1]);
        }
    }
    cout<<dp[1][n];
    
}