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
//ll MOD = 1000000007;
ll MOD = 998244353;
//vector<mint> dp(N, Mint);
//vector<vector<mint>> dp2(N, vector<mint>(N, Mint));
//vector<vector<vector<mint>>> dp3(N, vector<vector<mint>>(N, vector<mint>(N, Mint)));
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
const int MAXcomb = 10000010;
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
  rep(i, K) res *= (N-i);
  mint k = 1;

  rep(i, K) k *= (i+1);
  res /= k;
  return res;
}
//第二種スターリング数
const ll MAXStir2 = 3010;
vector<vector<mint>> Stir2memo(MAXStir2, vector<mint>(MAXStir2, Mint));
vector<mint> Bellmemo(MAXStir2, Mint);
void Stir2init(){
  Stir2memo[0][0] = 1;
  rep(i, MAXStir2-1)rep(j, i+1)Stir2memo[i+1][j+1] = Stir2memo[i][j] + Stir2memo[i][j+1] * (j+1);
  rep(i, MAXStir2){
    Bellmemo[i] = 0;
    rep(j,i+1) Bellmemo[i] += Stir2memo[i][j];
  }
}
mint Stir2(ll i, ll j){//区別できるi個をjグループに分ける場合の数
  if(i < 0 || j < 0 || i < j) return 0;
  return Stir2memo[i][j];
}
mint Bell(ll x){//区別できるx個をグループ分けする方法全ての場合の数
  if(x < 0) return 0;
  return Bellmemo[x];
}
mint kai_mod(ll K){
  if(K < 0) return 0;
  if(K == 0) return 1;
  return kai_mod(K-1) * K;
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




ll N;
mint memo[10000010];
void make_2(){
  memo[0] = 1;
  for(ll i = 1; i <= N; i++){
    memo[i] = memo[i-1] * 2;
  }
}
void solve(){
  mint ans = pow_mod(3, N);
  make_2();
  for(ll i = N/2+1; i <= N; i++){
    mint add = comb(N, i) * memo[N-i];
    ans -= add;
  }
  for(ll i = N/2+1; i <= N; i++){
    mint add = comb(N, i) * memo[N-i];
    ans -= add;
  }
  ans.get();
}
int main(){
  COMinit();
  cin >> N;
  solve();
}
