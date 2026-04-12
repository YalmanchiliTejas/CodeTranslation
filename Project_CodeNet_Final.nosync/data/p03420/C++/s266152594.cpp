#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

signed main(){

  int n,k; cin >> n >> k;
  if(k == 0){
    cout << n*n << endl;
    return 0;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans += (n/i) * max(0LL,i-k);
    ans += max(0LL,(n%i)-k+1);
  }
  cout << ans << endl;

  return 0;
}
