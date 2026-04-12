#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll mod = 1e9+7;
int main(){
  int n;
  cin >> n;
  vector<ll> v(n);
  vector<ll> csum(n+1);
  rep(i,n) cin >> v[i];
  rep(i,n+1){
    if (i == 0) continue;
    else csum[i] = (csum[i-1] + v[i-1])%mod;
  }
  ll ans = 0;
  int id = 1;
  rep(i,n-1){
    ll tmp = (v[i]*csum[n])%mod - (v[i]*csum[id])%mod;
    if (tmp < 0) tmp+=mod; 
    ans += tmp;
    ans %=mod;
    id++;
  }
   cout << ans << endl;
  return 0;
}
