#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin>>n;
  int mod=1000000007;
  long long a[n];
  long long ans=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  long long sum=0;
  for(int i=0;i<n;i++){
    sum+=a[i];
  }
  for(int i=0;i<n-1;i++){
    sum-=a[i];
    sum%=mod;
    if(sum<0){
      sum+=mod;
    }
    ans+=sum*a[i]%mod;
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;
}