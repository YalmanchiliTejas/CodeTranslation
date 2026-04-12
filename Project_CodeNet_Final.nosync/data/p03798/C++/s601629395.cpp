#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 1e9;
const ll INFll = 1e18;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

// aのn乗をMODで割りながら計算する
ll modpow(ll a, ll n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1; // right shift
  }
  return res;
}

// MODを法としたaの逆元を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}

int main(){
  int N;
  string t;
  cin>>N>>t;
  for (int i(1);i<=2;i++){
    for (int j(1);j<=2;j++){
      int ans[100000] = {0};
      string s = t;
      ans[0] = i;
      ans[1] = j;
      if (i == 2) s[0] = (s[0] == 'o'? 'x' : 'o');
      if (j == 2) s[1] = (s[1] == 'o'? 'x' : 'o');
      for (int k(2);k<N;k++){
        if (s[k-1] == 'o'){
          ans[k] = ans[k-2];
        }else{
          ans[k] = (ans[k-2] == 1? 2:1);
        }
        if (ans[k] == 2){
          s[k] = (s[k] == 'o'? 'x' : 'o');
        }
      }
      //for (int i(0);i<N;i++) cout << ans[i] << " ";
      if ((s[N-1] == 'o' && ans[N-2] == ans[0]) || (s[N-1] == 'x' && ans[N-2] * ans[0] == 2)){
        if ((s[0] == 'o' && ans[N-1] == ans[1]) || (s[0] == 'x' && ans[N-1] * ans[1] == 2)){
          for (int k(0);k<N;k++){
            if (ans[k] == 1){
              cout << 'S';
            }else{
              cout << 'W';
            }
          }
          cout << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
