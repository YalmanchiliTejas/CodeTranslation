#include<bits/stdc++.h>
using namespace std;
long long n,a[3003],dp[3003][3003];
int main(){
cin>>n;
for(int k=1;k<=n;k++)
    cin>>a[k];
for(int k=1;k<=n;k++)
    dp[k][k]=a[k];
for(int len=2;len<=n;len++){
   for(int i=len;i<=n;i++){
    int k=i-len+1;

    dp[k][i]=max(-dp[k+1][i]+a[k],-dp[k][i-1]+a[i]);
   }
}

cout<<dp[1][n];
return 0;
}
