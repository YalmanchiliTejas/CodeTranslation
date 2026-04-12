#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;



int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> acum(n+1);

  acum[0] = 0;
  rep(i,n) {
    cin >> a[i];
    a[i] %= mod;
    acum[i+1] += a[i]+acum[i];
    acum[i+1] %= mod;
  }

  ll ans = 0;

  rep(i,n-1){
    ans += (a[i]*(acum[n] - acum[i+1]+mod));
    ans %= mod;
  }
  
  cout << ans << endl;
  
}
