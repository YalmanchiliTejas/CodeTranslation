#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, n) for(int i = 1; i < n; i++)
#define P pair<int, int>
typedef long long ll;
const int mod = 1e9+7;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//繰り返し自乗法による累乗計算
//a**n
int pow(int a, int n){
  if(n == 0) return 1;
  if(n%2 == 0){
    int res = pow(a, n/2);
    return res * res;
  }
  return a * pow(a, n-1);
}
//繰り返し自乗法によるmod累乗計算
//a**n (mod)
int modpow(int a, int n){
  if(n == 0) return 1;
  if(n%2 == 0){
    int res = modpow(a, n/2);
    return res * res % mod;
  }
  return a * modpow(a, n-1) % mod;
}
//組み合わせ
//nCa
int com(int n, int a){
  int x = 1, y = 1;
  rep(i,a){
    x *= n-i;
    y *= i+1;
  }
  int res = x / y;
  return res;
}
//組み合わせ(mod)
//nCa (mod)
int modcom(int n, int a){
  int x = 1, y = 1;
  rep(i, a){
    x = x * (n-i) % mod;
    y = y * (i+1) % mod;
  }
  int ans = x * modpow(y, mod-2) % mod;
  return ans;
}
//gcd 最大公約数
int gcd(int x, int y){
  if(x % y == 0) return y;
  return gcd(y, x%y);
}
//lcm 最小公倍数
int lcm(int x, int y){
  return x * y / gcd(x, y);
}
//ngcd n個の最大公約数
int ngcd(vector<int> a){
  int res;
  res = a[0];
  for(int i = 1; i < a.size() && res != 1; i++) {
    res = gcd(a[i], res);
  }
  return res;
}
//nlcm n個の最小公倍数
int nlcm(vector<int> a) {
  int res;
  res = a[0];
  for (int i = 1; i < a.size(); i++) {
    res = lcm(res, a[i]);
  }
  return res;
}
// 素数判定
bool isprime(int x){
  int i;
  if(x < 2) return false;
  else if(x == 2) return true;
  if(x % 2 == 0) return false;
  for(i = 3; i*i <= x; i += 2){
    if(x % i == 0) return false;
  }
  return true;
}
// 桁和
int digsum(int x){
  int res = 0;
  while(x > 0){
    res += x % 10;
    x /= 10;
  }
  return res;
}


int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 1001001001;
  for(int i = 0; i <= max(x, y) * 2; i += 2){
    int A = max((int)0, x - i/2) * a;
    int B = max((int)0, y - i/2) * b;
    int AB = i * c;
    ans = min(ans, A+B+AB);
  }
  cout << ans << endl;
}




