#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,i,mod=1e9+7,ans=0;
  cin>>n;
  vector<int64_t> a(n),b(n);
  for(i=0;i<n;i++) cin>>a.at(i);
  b.at(n-1)=a.at(n-1);
  for(i=n-2;i>=0;i--) b.at(i)=(a.at(i)+b.at(i+1))%mod;
  for(i=0;i<n-1;i++) ans=(ans+a.at(i)*b.at(i+1)%mod)%mod;
  cout<<ans<<endl;
}