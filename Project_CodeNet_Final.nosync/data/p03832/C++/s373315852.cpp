#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

#define MAX_N 1010
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll perm(ll a, ll b){
    if(a < b) return 0;
    ll tmp = finv[a-b] % MOD;
    return tmp * fac[a] % MOD;
}


long long modPow(long long x, long long n){
  if(n == 0) return 1;
  if(n % 2 == 0) {
    long long sqrtX = modPow(x,n/2);
    return sqrtX * sqrtX % MOD ;
  }else{
    return x * modPow(x,n-1) % MOD;
  }
}

ll dp[MAX_N][MAX_N];
int main(){
  COMinit();
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  dp[0][0] = 1;

  FOR(i,1,n+1){
    rep(j,n+1){
      (dp[i][j] += dp[i-1][j]) %= MOD;
      if(a > i || i > b){
        continue;
      }
      // i人グループをk組み作る
      ll tmp = 1;
      ll tmp2 = finv[0];
      FOR(k,1,d+1){
        if(j + k*i > n) break;

        (tmp *= COM((n-j)-i*(k-1),i)) %= MOD;
        (tmp2 *= inv[k]) %= MOD;

        if(k < c) continue;
        dp[i][j+i*k] += ((dp[i-1][j] * tmp) % MOD) * tmp2;
        dp[i][j+i*k] %= MOD;
      }

    }
  }
  // rep(i,n+1){
  //   rep(j,n+1){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << dp[n][n] << endl;
  return 0;
}
