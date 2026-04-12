#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;cin>>n;
  vector<long long> a(n);
  for(int i=0; i<n; ++i) cin>>a[i];
  long long sum=0,cnt=0;
  for(int i=1; i<n; ++i) sum+=a[i];
  cnt+=a[0]%1000000007*(sum%1000000007);
  for(int i=1; i<n; ++i){
    sum-=a[i];
    cnt+=a[i]%1000000007*(sum%1000000007);
    cnt%=1000000007;
  }
  cnt%=1000000007;
  cout<<cnt<<endl;
  return 0;
}