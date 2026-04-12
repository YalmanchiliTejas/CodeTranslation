#include <bits/stdc++.h>
#define rep(i,e,n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll mod=1000000007;



int main(){
  int n;
  cin >> n;
  ll sum=0;
  vector<ll> a(n);
  rep(i,0,n){
    cin >> a[i];
    sum= (sum + a[i])%mod;
    }
//  cout << sum << endl;
  vector<ll> t(n);
  t[0]=(sum-a[0]+mod)%mod;
  rep(i,1,n){
    t[i] = (t[i-1]-a[i]+mod)%mod;
  }
  ll ans=0;
  rep(i,0,n){
    ans= (ans + t[i]*a[i]%mod)%mod;
//    cout << t[i] << ' ' << a[i] << endl;
//    cout << ans << endl;
  }
  cout << ans << endl;

}