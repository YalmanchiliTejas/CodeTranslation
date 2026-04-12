#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define inf 1000000000000000
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main(){
IOS;
lli n,i,j;
cin>>n;
lli a[n];
for(i=0;i<n;i++){
    cin>>a[i];
}
lli dp[n][n];
for(i=0;i<n;i++){
    if(n%2){
        dp[i][i]=a[i];
    }
    else{
        dp[i][i]=-a[i];
    }
}
for(i=n-1;i>=0;i--){
    for(j=i+1;j<n;j++){
        if(n%2){
            if((j-i+1)%2==0){
                lli mini=inf;
                mini=min(dp[i+1][j]-a[i],mini);
                mini=min(dp[i][j-1]-a[j],mini);
                dp[i][j]=mini;
            }
            else{
                lli maxi=-inf;
                maxi=max(dp[i+1][j]+a[i],maxi);
                maxi=max(dp[i][j-1]+a[j],maxi);
                dp[i][j]=maxi;
            }
        }
        else{
            if((j-i+1)%2==0){
                lli maxi=-inf;
                maxi=max(dp[i+1][j]+a[i],maxi);
                maxi=max(dp[i][j-1]+a[j],maxi);
                dp[i][j]=maxi;
            }
            else{
                lli mini=inf;
                mini=min(dp[i+1][j]-a[i],mini);
                mini=min(dp[i][j-1]-a[j],mini);
                dp[i][j]=mini;
            }
        }
    }
}
cout<<dp[0][n-1]<<endl;
}
