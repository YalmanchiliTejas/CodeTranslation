#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
int main(){
  int64_t n,sum=0,ans=0;
  cin >> n;
  int a[n];
  vector<int64_t> b(n+1,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
    b[i+1]=b[i]+a[i];
  }
  for(int i=0;i<n;i++){
    sum=(b[n]-b[i+1])%mod;
    ans+=a[i]*sum;
    ans%=mod;
  }
  cout << ans << endl;
}