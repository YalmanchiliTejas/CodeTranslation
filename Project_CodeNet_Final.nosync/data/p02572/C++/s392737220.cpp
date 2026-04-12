#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> a(n);
  int mod=1000000007;
  long long total=0;
  for (int i=0; i<n; i++){
    cin>>a[i];
    total+=a[i];
    total%=mod;
  }
  
  long long ans=0;
  
  for (int i=0; i<n; i++){
    total-=a[i];
    if (total<0) total+=mod;
    ans+=a[i]*total;
    ans%=mod;
  }
  cout<<ans<<endl;
}