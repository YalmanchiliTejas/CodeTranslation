#include <iostream>
#include <string>
// #include <vector>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std;
using ll = long long;
// using P = pair<int,int>;
const int mod = 1000000007;
int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  int ans = 0;
  int x=0;
  rep(i,n){
    ans = ((ll)ans + (ll)a[i]*x)%mod;
    x = ( x + a[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}