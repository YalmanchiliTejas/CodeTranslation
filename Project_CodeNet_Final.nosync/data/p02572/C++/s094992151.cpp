#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  ll s=0;
  ll ans=0;
  for(int i=0;i<n;++i){
    cin >> a[i];
    s+=a[i];
    s%=MOD;
  }

  for(int i=0;i<n;++i){
    s-=a[i];
    if(s<0)s+=MOD;

    ans+=a[i]*s;
    ans%=MOD;
  }
  cout << ans << endl;
  return 0;
}
