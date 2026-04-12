#include <bits/stdc++.h>
using namespace std;

int main() {
int64_t n;
  cin>>n;
  int64_t ans;
  ans=0;
  int64_t t=1000000007;
  vector<int64_t> vec(n); 
   //cout<<1<<endl;//qqqqqqq
  for(int64_t i=0;i<n;i++){
  cin>>vec.at(i);
  }
  //cout<<1<<endl;//qqqqqqq
  for(int64_t j=0;j<n;j++){
  ans=ans+vec.at(j);
  }
   //cout<<1<<endl;//qqqqqqq
  ans=ans%t;
  ans=(ans*ans)%t;
  for(int64_t i=0;i<n;i++){
  ans=(ans+t-((vec.at(i)%t)*(vec.at(i)%t))%t)%t;
  }
  if(ans%2==0){cout<<ans/2<<endl;}
  else{cout<<(ans+t)/2<<endl;};
}
