#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 9999999999999999;
using ll = long long;
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}





int main(){
  ll N;
  cin>>N;
  ll a[N];
  ll temp1 = 0;
  ll temp2 = 0;
  ll ans;
  for(ll i = 0;i<N;i++){
    cin>>a[i];
  }
  for(ll i = 0;i<N;i++){
    temp1 += a[i];
    temp1 = temp1%MOD;
    temp2+=a[i]*a[i]%MOD;
    temp2 = temp2%MOD;
  }
  temp1 = temp1*temp1%MOD;
  if(temp1<temp2){
    ans = temp1+MOD-temp2;
    ll kkk = modinv(2,MOD);
    cout << ans*kkk%MOD << endl;
  }
  else{
    ans = temp1-temp2;
    ll kkk = modinv(2,MOD);
    cout << ans*kkk%MOD << endl;
  }
  return 0;
}