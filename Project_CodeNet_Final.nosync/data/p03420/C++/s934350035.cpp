#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

main(){
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  if(k==0) ans = n*n;
  else{
    ans += ((n-k)*(n-k+1)/2);
    for(int i=k+1;i<=n;++i){
      ll val = (n/i) - 1;
      ans += (val*(i-k));
      ans += max(0LL,(n%i) - k+ 1);
    }
  }
  cout << ans << endl;
}