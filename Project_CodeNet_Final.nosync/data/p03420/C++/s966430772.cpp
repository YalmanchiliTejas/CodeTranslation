#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,k;
  cin>>n>>k;
  long long ans=0;
  if(k==0) {
    ans=n*n;
    cout<<ans<<endl;
  }
  else{
  for(long long b=k+1;b<=n;b++){
    long long block=n/b;
    ans+=block*(b-k);
    long long amari=n%b;
    amari-=k-1;
    if(amari>0) ans+=amari;
  }
  cout<<ans<<endl;
  }
}
