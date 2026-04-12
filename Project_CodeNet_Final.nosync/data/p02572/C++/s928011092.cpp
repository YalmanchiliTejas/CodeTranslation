#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define mod 1000000007
int main(){
  int n;
  cin>>n;
  ll a[n];
  ll suff[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }
  suff[n-1]=a[n-1];
  for(int i=n-2;i>=0;i--){
    suff[i]=(suff[i+1]+a[i])%mod;
  }
  ll ans=0;
  for(int i=0;i<n-1;i++){
    ans=(ans%mod+(a[i]*suff[i+1])%mod)%mod;
  }
  cout<<ans;
  return 0;
}