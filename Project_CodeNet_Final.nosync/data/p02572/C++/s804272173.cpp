#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int main(){
  int n;cin>>n;
  long long a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  long long pre[n];
  pre[0]=a[0];
  long long ans=0;
  for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
  for(int i=n-1;i>=1;i--){
    ans=(ans+(a[i]%MOD)*(pre[i-1]% MOD))%MOD;
  }
  cout<<ans<<endl;
}