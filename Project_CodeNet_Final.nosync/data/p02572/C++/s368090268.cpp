#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
  int MOD = 1000000007;
  int n; cin>>n;
  ll sum=0,ans=0;
  vector<ll> a(n);
  rep(i,n) {
    cin>>a[i];
    sum+=a[i];
    sum%=MOD;
  }

  rep(i,n-1) {
    sum-=a[i];
    if(sum<0) sum+=MOD;
    ans+=a[i]*sum%MOD;
    ans%=MOD;
  }

  cout<<ans<<endl;
}
