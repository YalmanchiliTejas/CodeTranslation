#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define REP(i, n) for(ll i = 1; i < (ll)(n); i++)
#define P pair<ll, ll>
typedef long long ll;
const ll mod = 1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//繰り返し自乗法によるmod累乗計算
//a = 底、　n = 指数
ll modpow(ll a, ll n){
  if(n == 0) return 1;
  if(n%2 == 0){
    ll res = modpow(a, n/2);
    return res * res % mod;
  }
  return a * modpow(a, n-1) % mod;
}
//nCa 
ll comb(ll n, ll a){
  ll x = 1, y = 1;
  rep(i, a){
    x = x * (n-i) % mod;
    y = y * (i+1) % mod;
  }
  ll ans = x * modpow(y, mod-2) % mod;
  return ans;
}

ll a[55], p[55];

ll f(ll n, ll x){
  if(n == 0 && x == 1) return 1;
  else if(x == 1) return 0;
  else if(x <= a[n-1] + 1) return f(n-1, x-1);
  else if(x == a[n-1] + 2) return p[n-1]+1;
  else if(x <= a[n-1]*2+2) return f(n-1, x-2-a[n-1]) + p[n-1] + 1;
  else if(x == a[n-1]*2+3) return p[n-1]*2+1;
}

int main(){
  ll n, x;
  cin >> n >> x;
  a[0] = 1; p[0] = 1;
  for(int i = 0; i <= 50; i++){
    a[i+1] = a[i] * 2 + 3;
    p[i+1] = p[i] * 2 + 1;
  }
  ll ans = f(n, x);
  cout << ans << endl;
}




