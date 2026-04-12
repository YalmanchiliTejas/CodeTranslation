#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int64_t mod=1000000007;
  vector<int64_t>a(n);
  int64_t sum=0;
  int64_t ans=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    sum+=a.at(i);
  }
  int64_t tmp;
  for(int i=0;i<n-1;i++){
    sum-=a.at(i);
    tmp=sum;
    tmp%=mod;
    tmp*=a.at(i);
    tmp%=mod;
    ans+=tmp;
    ans%=mod;
  }
  cout<<ans<<endl;
}