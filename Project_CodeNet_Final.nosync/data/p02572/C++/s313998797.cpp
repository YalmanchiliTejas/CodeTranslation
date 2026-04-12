#include<bits/stdc++.h>
using namespace std;
#define int int64_t
#define mod (1000000007)
signed main(){
  int n,b,sum=0;
  vector<int> a;
  int c={};
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>b;
    a.push_back(b);
    c+=b;
  }
  for(int i=0;i<n-1;i++){
    sum+=(((c-a[i])%mod)*a[i]);
    c-=a[i];
    sum%=mod;
  }
  cout<<sum<<"\n";
  return 0;
}