#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll P[52], S[52];
int main(){
  ll n, k; cin >> n >> k;
  P[0] = S[0] = 1;
  for(ll i = 1; i <= n; i++){
    P[i] = 2*P[i-1] + 1;
    S[i] = 2*S[i-1] + 3;
  }
  ll ans = 0, cnt = n, num = k;
  while(num){
    if(num*2 > S[cnt]){
      if(cnt >= 1) ans += P[cnt-1];
      ans++;
      if(cnt >= 1) num -= S[cnt-1] + 2;
      else break;
    }
    else{
      num--;
    }
    cnt--;
  }
  cout << ans << endl;
}
    