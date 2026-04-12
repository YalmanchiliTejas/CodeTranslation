#include<bits/stdc++.h>
using namespace std;
void solve(){
  long long mod,ans=0;
  mod=1e9+7;
  int n;
  cin>>n;
  vector<long long> v(n);
  vector<long long> sum(n);
  cin>>v[0];
  sum[0]=v[0];
  for (int i=1 ;i<n;i++){
    cin>>v[i];
    sum[i]=(sum[i-1]+v[i]);
  }
  long long k=sum[n-1];
  for(int i=0;i<n;i++){
    ans+=((v[i]%mod)*((k-sum[i])%mod))%mod;
    ans=ans%mod;
  }
  cout<<(ans%mod)<<endl;
}
int main(){
  solve();
  return 0;
}