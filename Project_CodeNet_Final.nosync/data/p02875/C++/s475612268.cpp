#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d>>(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

#define P 998244353
#define N_MAX 10000000
typedef long long int ll;
ll fac[N_MAX+1];
ll inv[N_MAX+1];
ll finv[N_MAX+1];

ll comb(ll n, ll k){
  if(n<0||k<0||n<k) return 0;
  return (((fac[n]*finv[n-k])%P)*finv[k])%P;
}
ll perm(ll n, ll k){
  if(n<0||k<0||n<k) return 0;
  return (fac[n]*finv[n-k])%P;
}

void init(){
  fac[0] = finv[0] = fac[1] = finv[1] = inv[1] = 1;
  for(int i = 2; i <= N_MAX; i++){
    fac[i] = (fac[i-1]*i)%P;
    inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
    finv[i] = (finv[i-1]*inv[i])%P;
  }
}
ll pp(ll a, ll b){
  return (a * b)%P;
}
ll mpow(ll a, ll b, ll p = -1){
  ll ret = 1, num = a;
  if(p==-1){
    while(b>0){
      if(b%2) ret *= num;
      num = num * num;
      b /= 2;
    }
  }else{
    while(b>0){
      if(b%2) ret = (ret*num)%p;
      num = (num*num)%p;
      b /= 2;
    }
  }
  return ret;
}
int main(int argc, char const *argv[]) {
  init();
  ll n;std::cin >> n;
  ll ans = mpow(3, n, P);
  ll sub = 0;
  for(ll i=n/2+1;i<=n;i++){
    ll tmp = comb(n, i);
    tmp = (tmp * mpow(2, n-i, P))%P;
    sub = (sub + tmp)%P;
  }
  // 3^n -
  std::cout << (ans-(2*sub)%P+P)%P << '\n';
  return 0;
}
