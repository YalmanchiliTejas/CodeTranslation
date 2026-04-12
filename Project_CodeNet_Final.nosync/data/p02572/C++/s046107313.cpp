#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n;
  cin >> n;
  ll s=0;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  
  ll ans=0;
  for(int i=0;i<n;i++){
    ans+=s*a[i];
    ans%=1000000007;
    s+=a[i];
    s%=1000000007;
  }
  
  cout << ans << endl;
  
}