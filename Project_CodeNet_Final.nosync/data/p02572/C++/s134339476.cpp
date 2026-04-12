#include<bits/stdc++.h>
using namespace std;

int main() {
long long n;
long long M=1000000007;
cin>>n;
long long a[n];
long long dp[n+1]={0};
for(long long i=0;i<n;i++){
  cin>>a[i];
}
for(long long i=0;i<n;i++){
  dp[i+1]=(dp[i]+a[i])%M;
}
long long ans=0;
for(long long i=0;i<n-1;i++){
  ans+=(a[i]*(dp[n]-dp[i+1]+M))%M;
  ans=ans%M;
}
cout<<ans<<endl;
    return 0;
}
