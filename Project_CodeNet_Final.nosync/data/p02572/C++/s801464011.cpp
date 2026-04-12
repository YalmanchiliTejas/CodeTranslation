#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<ll> a(n+1); for(int i = 1;i<=n;i++) cin >> a[i];
  ll MOD = 1000000000+7;

  vector<ll> mult(n+1,0);
  mult[n] = a[n]%MOD;
  for(int i = n;i>=1;i--){
    mult[i-1] = mult[i]+a[i-1];
    mult[i-1] %= MOD;
    //cout << "i-1: " << i-1 << " mult: " << mult[i-1] << endl;
  }

  ll ans = 0;
  for(int i = 1;i<=n-1;i++){
    ans += a[i]*mult[i+1];
    ans %= MOD;
    //cout << ans << endl;
  }
  
  cout << ans << endl;
  
  return 0;
}
