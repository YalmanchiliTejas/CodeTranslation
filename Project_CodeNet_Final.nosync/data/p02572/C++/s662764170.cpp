#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin>>n;
  int mod = 1000000007;
  vector<int>a(n);
  long long sum=0;
  long long ans=0;
  for(int i=0;i<n;++i){
    cin>>a[i];
    sum+=a[i];
    sum%=mod;
  }
  for(int i=0;i<n;++i){
    sum-=a[i];
    if(sum<0)
      sum+=mod;
    ans+=sum*a[i];
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;
}
