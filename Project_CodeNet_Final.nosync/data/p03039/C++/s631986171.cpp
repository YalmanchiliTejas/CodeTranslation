#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

//-------------------------------------------------------------------
#define P 1000000007
#define N_MAX 2000000
typedef long long int ll;
ll fac[N_MAX+1];
ll inv[N_MAX+1];
ll finv[N_MAX+1];

ll comb(ll n, ll k){
  if(n<0||k<0||n<k) return 0;
  return (((fac[n]*finv[n-k])%P)*finv[k])%P;
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
//-------------------------------------------------------------------
int main(int argc, char const *argv[]) {
  ll n, m, k, ans = 0;std::cin >> n >> m >> k;
  init();
  ll t = comb(n*m-2, k-2); //point a, bが選ばれる選び方はn*m-2 C k-2
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      ll left = (((i*(i+1))/2)%P + (((n-1-i)*(n-i))/2)%P)%P;
      ll up = (((j*(j+1))/2)%P + (((m-j-1)*(m-j))/2)%P)%P;
      ll tmp = (pp(up, n) + pp(left, m))%P;
      ans = (ans+pp(t, tmp))%P;
    }
  }
  std::cout << pp(ans, inv[2]) << '\n';
  return 0;
}
