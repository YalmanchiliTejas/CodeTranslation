#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
ll n;
cin>>n;
ll a[n+1];
for(int i=1;i<=n;i++) cin>>a[i];
ll dp[n+1][n+1];
memset(dp,0,sizeof(dp));

for(int i=1;i<=n;i++) dp[i][i]=a[i];

for(int len=1;len<n;len++){
ll i=1;
for(int j=i+len;j<=n;j++){
    dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
    i++;
}

}

cout<<dp[1][n]<<endl;



}