#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <cstdint>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
#define chmin(x, y) x = min(x, y);
#define chmax(x, y) x = max(x, y);
void BinarySay(ll x, ll y = 60){rep(i, y) cout << (x>>(y-1-i) & 1); cout << endl;}
const ll INFL = 1LL << 60;//10^18 = 2^60
ll MOD = 1000000007;
//ll MOD = 998244353;
//ll MOD = 924844033;
struct mint{
  ll x;
  mint(ll x=0):x(x % MOD){}
  mint& operator+=(const mint a){
    (x += a.x) %= MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    (x += MOD-a.x) %= MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x *= a.x) %= MOD;
    return *this;
  }
  mint& operator%=(const mint a){
    (x %= a.x);
    return *this;
  }
  mint& operator++ (int){
    (x += 1) %= MOD;
    return *this;
  }
  mint& operator-- (int){
    (x += MOD-1) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
  mint operator%(const mint a) const{
    mint res(*this);
    return res%=a;
  }
  mint po(ll t) const{
    if(!t) return 1;
    mint a = po(t>>1);
    a *= a;
    if(t&1) a *= *this;
    return a;
  }
  mint inverse() const{
    return po(MOD-2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inverse();
  }
  mint operator/(const mint a) const{
    mint res(*this);
    return res/=a;
  }
  bool operator == (const mint a){
    return this->x == a.x;
  }
  bool operator != (const mint a){
    return this->x != a.x;
  }
  void get(){
    cout << x << endl;
  }
  void ge(){
    cout << x << " ";
  }
};const mint Mint = 0;


mint pow_mod(ll x, ll k){
  mint res = 1;
  mint a = x;
  while(k > 0){
    if(k % 2){
      res *= a;
    }
    a *= a;
    k /= 2;
  }
  return res;
}

ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}

mint inverse(ll x){return pow_mod(x, MOD-2);}

//二項演算
const int MAXcomb = 200010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAXcomb; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
mint comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    mint res = fac[n];
    res *= finv[k] * finv[n-k];
    return res;
}

mint comb_naive(ll N, ll K){//Kが小さい時
  mint res = 1;
  rep(i, K) res *= (N-i) % MOD;
  mint k = 1;

  rep(i, K) k *= (i+1);
  res /= k;
  return res;
}

const ll MAXkai = 200010;
ll kai_memo[MAXkai];
mint kai(ll N){
  mint res;
  if(kai_memo[N] != 0) res = kai_memo[N];
  else if(N <= 1) res = 1;
  else res = kai(N-1) * N;
  kai_memo[N] = res.x;
  return res;
}

//約数の列挙O(√n)
vector<ll> divisor(ll n){
    vector<ll> res(0);
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

ll disit(ll x, ll d = 10){
  ll res = 0;
  while(x){
    res++;
    x /= d;
  }
  return res;
}


void solve(){
  ll N, M, K;
  cin >> N >> M >> K;
  mint ans = 0;
  mint one = 1;
  for(ll i = 1; i <= N; i++){
    mint add = one * (N - i) * M * M * i;
    ans += add;
  }
  swap(N, M);
  for(ll i = 1; i <= N; i++){
    mint add = one * (N - i) * M * M * i;
    ans += add;
  }
  ans *= one * comb_naive(N*M-2, K-2);
  ans.get();
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
