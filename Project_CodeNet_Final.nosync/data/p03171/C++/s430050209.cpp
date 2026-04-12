#include<bits/stdc++.h>
using namespace std;
long long dp[3003][3003],n,a[3002];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(r==l) dp[r][l]=a[l];
            else{
                dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}