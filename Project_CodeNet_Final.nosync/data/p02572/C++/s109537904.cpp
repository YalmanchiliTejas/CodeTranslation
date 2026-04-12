#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;


int main() {
  intll  n  ;
  cin >> n ;
  vector<intll> v(n) ;
  intll total = 0 ;
  rep(i,n){
    cin >> v.at(i) ;
    total += v.at(i) ;
  }
  intll ans = 0 ;
  
  for(int i=0;i<n;i++){
      total -= v.at(i)  ;
      ans += (v.at(i)%MOD) * (total%MOD) % MOD ;
      ans %= MOD ;
    }

  
  cout << ans ;
    
}
