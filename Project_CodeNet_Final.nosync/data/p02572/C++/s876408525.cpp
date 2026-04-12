#include <bits/stdc++.h>
using namespace std;

int64_t modpow(int64_t x, int64_t n) {
  const int MOD = 1000000007;

  x = x%MOD;
  if(n==0) return 1;  //再帰の終了条件

  else if(n%2==1) {
    return (x*modpow(x, n-1))%MOD;  //nが奇数ならnを1ずらす
  }
  else return modpow((x*x)%MOD, n/2)%MOD;  //nが偶数ならnが半分になる
}


int main() {
  int n;
  cin>>n;
  int64_t a[n];
  for(int i=0; i<n; i++) cin>>a[i];
  const int MOD = 1000000007;

  int64_t sum = 0;
  for(int i=0; i<n; i++) {
    sum += a[i];
    sum = sum%MOD;
  }

  int64_t nijou = (sum*sum)%MOD;
  int64_t rest = 0;
  for(int i=0; i<n; i++) {
    rest += (a[i]*a[i])%MOD;
    rest = rest%MOD;
  }

  int64_t sub = nijou - rest;
  if(sub<0) sub += MOD;

  int64_t ans = sub*(modpow(2, MOD-2));
  // int64_t ans = sub/2;
  ans = ans%MOD;

  cout<<ans<<endl;


  return 0;
}