#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
  int n;
  cin>>n;
  vector<long long> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  
  reverse(a.begin(),a.end());
  vector<long long> b(n);
  b.at(0)=a.at(0);
  for(int i=1;i<n;i++){
    b.at(i)=(b.at(i-1)+a.at(i))%mod;
  }
  reverse(b.begin(),b.end());
  reverse(a.begin(),a.end());
  
  long long ans=0;
  for(int i=0;i<n-1;i++){
    long long aa = a.at(i)*b.at(i+1) % mod;
    ans+=aa;
    ans%=mod;
  }
  cout<<ans<<endl;
}