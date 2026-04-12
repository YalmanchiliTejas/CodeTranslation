#include <iostream>
#include <string>
// #include <vector>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<int,int>;
const int mod = 1000000007;
int main(){
  ll n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  ll ans = 0;
  ll x=0;
  rep(i,n){
    ans = (ans + a[i]*x)%mod;
    x = ( x + a[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}