#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)
const ll mod = 1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];
  vector<ll> cumsum(n+1);
  rep(i,n+1){
    if (i == 0) continue;
    cumsum[i] = cumsum[i-1] + v[i-1];
    cumsum[i]%=mod; 
  }
  ll ans = 0;
  for (int i = 0; i < n;i++){
    ll tmp = cumsum[n] - cumsum[i+1];
    if (tmp < 0) tmp += mod;
    ans += v[i]*tmp;
    ans %=mod;
  }
  cout << ans << endl;

  



  

  return 0;
   

}
