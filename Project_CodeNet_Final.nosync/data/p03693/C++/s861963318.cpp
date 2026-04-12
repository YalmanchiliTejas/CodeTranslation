#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i < n; i++)
#define P pair<int, int>
typedef long long ll;
const ll mod = 1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//繰り返し自乗法による累乗計算
//a**n
ll pow(ll a, ll n){
  if(n == 0) return 1;
  if(n%2 == 0){
    ll res = pow(a, n/2);
    return res * res;
  }
  return a * pow(a, n-1);
}
//繰り返し自乗法によるmod累乗計算
//a**n (mod)
ll modpow(ll a, ll n){
  if(n == 0) return 1;
  if(n%2 == 0){
    ll res = modpow(a, n/2);
    return res * res % mod;
  }
  return a * modpow(a, n-1) % mod;
}
//組み合わせ
//nCa
ll com(ll n, ll a){
  ll x = 1, y = 1;
  rep(i,a){
    x *= n-i;
    y *= i+1;
  }
  ll res = x / y;
  return res;
}
//組み合わせ(mod)
//nCa (mod)
ll modcom(ll n, ll a){
  ll x = 1, y = 1;
  rep(i, a){
    x = x * (n-i) % mod;
    y = y * (i+1) % mod;
  }
  ll ans = x * modpow(y, mod-2) % mod;
  return ans;
}
//gcd 最大公約数
ll gcd(ll x, ll y){
  if(x % y == 0) return y;
  return gcd(y, x%y);
}
//lcm 最小公倍数
ll lcm(ll x, ll y){
  return x * y / gcd(x, y);
}
//ngcd n個の最大公約数
ll ngcd(vector<ll> a){
  ll res;
  res = a[0];
  for(ll i = 1; i < a.size() && res != 1; i++) {
    res = gcd(a[i], res);
  }
  return res;
}
//nlcm n個の最小公倍数
ll nlcm(vector<ll> a) {
  ll res;
  res = a[0];
  for (ll i = 1; i < a.size(); i++) {
    res = lcm(res, a[i]);
  }
  return res;
}
// 素数判定
bool isprime(ll x){
  ll i;
  if(x < 2) return false;
  else if(x == 2) return true;
  if(x % 2 == 0) return false;
  for(i = 3; i*i <= x; i += 2){
    if(x % i == 0) return false;
  }
  return true;
}
// 桁和
ll digsum(ll x){
  ll res = 0;
  while(x > 0){
    res += x % 10;
    x /= 10;
  }
  return res;
}


int main(){
  int r, g, b;
  cin >> r >> g >> b;
  int a = r * 100 + g * 10 + b;
  if(a % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}




