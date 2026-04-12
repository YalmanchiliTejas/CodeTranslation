#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  ll cnt=0;
  int mod=1e9+7;
  rep(i,n){
    cin>>a[i];
    cnt+=a[i];
    cnt%=mod;
  }
  ll ans=0;
  rep(i,n){
    cnt-=a[i];
    if(cnt<0)cnt+=mod;
    ans+=a[i]*cnt;
    ans%=mod;
  }
  cout<<ans<<endl;
}