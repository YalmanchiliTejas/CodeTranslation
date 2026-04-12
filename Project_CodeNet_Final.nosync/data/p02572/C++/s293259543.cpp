#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

using Pair = pair<int, int>;
using lint = long long;

 const int mod = 1e9 + 7;
// const int mod = 998244353;

template <typename T> vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
#define rep(i, n) for (int i = 0; i < (n); i++)
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
long long modinv(long long a, long long mod) {
  return modpow(a, mod - 2, mod);
}
int main(){
  int n;
  cin>>n;
  vector<lint> a(n);
  rep(i,n)cin>>a[i];
  lint s=0;
  rep(i,n){
    s+=a[i];
    s%=mod;
  }
  s*=s;
  s%=mod;
  rep(i,n){
    s-=a[i]*a[i];
    s%=mod;
  }
  cout<<(s+mod)*modinv(2,mod)%mod<<endl;
}
