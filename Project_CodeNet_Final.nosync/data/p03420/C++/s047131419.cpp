#include "bits/stdc++.h"

using namespace std;

int main(){
  long long int n,k;
  cin>>n>>k;
  long long int ans=0;
  for(long long int i=k+1;i<=n;++i){
    ans+=((n-k)/i+1)*(i-k);
    if(n%i>=k)ans-=i-(n%i)-1;
  }
  if(k==0)ans=n*n;
  cout<<ans<<endl;
}