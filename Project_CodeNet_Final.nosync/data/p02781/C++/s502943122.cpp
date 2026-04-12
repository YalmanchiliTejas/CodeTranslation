#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back

#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll keta(ll n){
  string s = to_string(n);
  ll num = s.size();
  return num;
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w){}
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;



vi MP(string s){
  vi A(s.size()+1);
  A[0] = -1;
  int j = -1;
  rep(i,s.size()) {
    while(j >= 0 && s[i] != s[j]) j = A[j];
    j++;
    A[i+1] = j;
  }
  return A;
}

vi Manacher(string s){
  vi R(s.size());
  int i = 0, j = 0;
  while(i < s.size()){
    while(i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]) ++j;
    R[i] = j;
    int k = 1;
    while(i-k >= 0 && i+k < s.size() && k+R[i-k] < j) R[i+k] = R[i-k], k++;
    i += k; j -= k;
  }
  return R;
}

vi Z_algorithm(string &s){
  vi Z(s.size());
  Z[0] = s.size();
  int i = 1, j = 0;
  while(i < s.size()){
    while(i+j < s.size() && s[j] == s[i+j]) j++;
    Z[i] = j;
    if(j == 0){++i; continue;}
    int k = 1;
    while(i+k < s.size() && k+Z[k] < j) Z[i+k] = Z[k], ++k;
    i += k; j -= k;
  }
  return Z;
}

const int MAX = 1e6+1;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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
long long COM(ll n, ll k){
  if(n >= MAX){
    ll tmp = 1;
    rep(i,k){
      tmp *= (n-i);
      tmp %= MOD;
    }
    return tmp*finv[k]%MOD;
  }

  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll POW(ll x, ll n){
  ll ret = 1;

  if(n < 0){// n < 0 にも対応
    n *= -1;
    x = inv[x];
  }

  while(0 < n){
    if(n%2 == 0){
      x = x*x%MOD;
      n /= 2;
    }
    else{
      ret = ret*x%MOD;
      n--;
    }
  }

  return ret;
}

int main(){
  string N; int K; cin >> N >> K;
  int n = N.size();

  int dp[n+1][K+1][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  /*
    dp[i][j][k]:i桁目まで決めてj個の非0を使って
    k = 0:そこまでの桁はNと一致
    k = 1:そこまでの桁で既にN以下であることが確定
  */
 
  rep(i,n) rep(j,K+1) {
    int num = N[i] - '0';

    // 1~9 を使用
    if(j < K) dp[i+1][j+1][1] += 9*dp[i][j][1];
    // 0 を使用
    dp[i+1][j][1] += dp[i][j][1];

    if(num == 0){
      // 0 を使用
      dp[i+1][j][0] += dp[i][j][0];
      continue;
    }
    // 以下 num != 0

    if(j < K){
      // num を使用
      dp[i+1][j+1][0] += dp[i][j][0];
      // 1~num-1 を使用
      dp[i+1][j+1][1] += (num-1)*dp[i][j][0];
    }
    // 0 を使用
    dp[i+1][j][1] += dp[i][j][0];
  }
  cout << dp[n][K][0] + dp[n][K][1] << endl;
}
