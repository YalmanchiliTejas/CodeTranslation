#include<bits/stdc++.h>
using namespace std;

int main(){
  int mod=1e9+7;
  int n;
  cin>>n;
  vector<int> a(n),b(n);
  for(int i=0; i<n; i++) cin>>a[i];
  b[n-1]=0;
  for(int i=1; i<n; i++) b[n-i-1]=(b[n-i]+a[n-i])%mod;
  int ans=0;
  for(int i=0; i<n; i++){
    ans=(ans+(int64_t)a[i]*b[i])%mod;
  }
  cout<<ans<<endl;  
}