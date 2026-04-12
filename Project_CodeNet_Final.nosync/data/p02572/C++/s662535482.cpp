#include<bits/stdc++.h>
using namespace std;
using Long = long long;

const Long MOD = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  vector<Long> v(n + 1) , ac(n + 1);
  for( int i = 1 ; i <= n ; ++i ) cin >> v[i];
  for( int i = 1 ; i <= n ; ++i ) ac[i] = ( ac[i - 1] + v[i] ) % MOD;
  Long ans = 0;
  for( int i = 2 ; i <= n ; ++i ) {
  	ans = ans + ( v[i] * ac[i - 1] % MOD ) ;
  	ans %= MOD;
  }
  cout << ans ;
  return 0;
}
