#include <bits/stdc++.h>
using namespace std;
 
//long long
using ll = long long;
 
// pair<int, int>
using PII = pair<int, int>;
 
//最大値、mod
const int MOD = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
 
//出力系
#define print(x) cout << x << endl
#define prints(x) cout << fixed << setprecision(10) << x << endl
#define printc(x) cout << setw(2) << setfill('0') << x << endl;
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()
 
//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
 
//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
 
// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}
 
// a = max(a, b), a = min(a, b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
// 階乗(MODをとる)
ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}
 
 
 
// 二項係数(MODとる、1 ≦ k ≦ n ≦ 10^7 程度)
// COMinit()
// COM(x, y)
// とコンビで使う
 
// テーブルを作る前処理
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};






int main(){
  ll a, b;
  cin >> a >> b;

  ll ans = 0;
  if(b == 0){
    cout << a * a << endl;
    return 0;
  }
  for (ll i = 1; i <= a; i++) {
      ans += max((ll)0, i - b)*(a / i) + max((ll)0, a % i - b + 1);
  }
  print(ans);
  return 0;
}
